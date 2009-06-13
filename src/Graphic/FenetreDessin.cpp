/*
    ==================================================
    Software : AMILab
    Authors  : Karl Krissian
    Email    : karl@bwh.harvard.edu

    AMILab is a language for image processing
    ==================================================
    Copyright (C) 1996-2005  Karl Krissian

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

    ================================================== 
   The full GNU Lesser General Public License file is in Devel/Sources/Prog/LesserGPL_license.txt
*/
//
//  Fichier : FenetreDessin.cpp
//
//  class de base permettant de creer une fenetre de dessin
//  Avec les fonctions de base : dessin de ligne, de polygones, etc ...
//  
//  Karl KRISSIAN		Sophia Antipolis, 	le 5-08-96
//

#include "FenetreDessin.hpp"
#include "StringUtils.hpp"

// TODO: get rid of the need of the X11 display




extern unsigned char      GB_debug;
#define aff_err(a) Si GB_debug AlorsFait fprintf(stderr,a);

#define SETARG(option,valeur) XtSetArg( args[n], option, valeur  ); n++;

FenetreDessin* FenetreDessin::_this;



//=====================================================================
// MEMBRES PROTEGES
//


BEGIN_EVENT_TABLE(FenetreDessin, wxFrame)
    EVT_CLOSE(FenetreDessin::OnClose)
END_EVENT_TABLE()

//=====================================================================
// MEMBRES PUBLICS

//---------------------------------------------------------------------
// Defaut: int type=CREATE_WINDOW
//
FenetreDessin::FenetreDessin(
							 wxWindow* parent, 
							 const std::string& titre, 
//                                      -------------
			      int hauteur, int largeur, int type):
      wxFrame( parent, -1, 
      wxString::FromAscii((char*)RemovePath(titre.c_str())),
      wxPoint(50,50), wxSize(largeur,hauteur))
{
    Chaine  WindowTitle;

  if (GB_debug) fprintf(stderr,"FenetreDessin::FenetreDessin title = %s \n",titre.c_str());
  WindowTitle = RemovePath(titre.c_str());
  _name = WindowTitle;

  Si GB_debug AlorsFait printf("Constructeur FenetreDessin() \n");

  _type = type;

  _palette_allouee = false;
  _palette = NULL;

#if defined(__MOTIF__)
  _pixmap_alloue = false;
  _fenetre_affichee = false;
#endif

  _this = this;

//  _parent = parent;
  _hauteur = hauteur;
  _largeur = largeur;

  CreateDrawingArea();

  _buttonpressed_callback = NULL;
  _buttonpressed_data     = NULL;

  _keypressed_callback = NULL;
  _keypressed_data     = NULL;

// TODO: set destroy callback  XtAddCallback(_fenetre,XmNdestroyCallback,CB_CloseWindow,this);
  CloseFunction = CloseData = NULL;

  _message_dialog = NULL;

  Si GB_debug AlorsFait printf("Fin Constructeur FenetreDessin() \n");

} // Constructeur FenetreDessin()


//---------------------------------------------------------------------
FenetreDessin :: Destructeur FenetreDessin()
//                                     -------------
{


  Si GB_debug AlorsFait fprintf(stderr,"FenetreDessin::~FenetreDessin() debut \n");
  // Remove callback to avoid calling this destructor anew

// TODO  XtRemoveCallback(_fenetre,XmNdestroyCallback,CB_CloseWindow, (void*)this);

  FreeContext();

  Si GB_debug AlorsFait fprintf(stderr,"FenetreDessin::~FenetreDessin() fin \n");

} // Destructeur FenetreDessin()



//---------------------------------------------------------------------
void FenetreDessin :: CreateDrawingArea( )
//                              --------------
{

//  _visual_info = NULL;
  _drawing_window = new wxDrawingArea(this,wxID_ANY);

} // CreateDrawingArea()



//---------------------------------------------------------------------
void FenetreDessin :: FreeDrawingArea( )
//                              ---------------
{

} // FreeDrawingArea()

//---------------------------------------------------------------------
void FenetreDessin :: CreateContext( )
//                              ------------
{

} // CreateContext()


//---------------------------------------------------------------------
void FenetreDessin :: FreeContext( )
//                              -----------
{
  if (_fenetre_affichee) {
  }

  // 
  if (GB_debug) fprintf(stderr,"FenetreDessin::FreeContext() \n");

} // FreeContext()



//---------------------------------------------------------------------
void FenetreDessin::AfficheFenetre( )
//                  --------------
{
  //char    nom_classe[6][20];

  aff_err("FenetreDessin::AfficheFenetre()\n");

/*
strcpy(nom_classe[PseudoColor],"PseudoColor");
  strcpy(nom_classe[GrayScale],  "GrayScale");
  strcpy(nom_classe[DirectColor],"DirectColor");
  strcpy(nom_classe[TrueColor],  "TrueColor");
  strcpy(nom_classe[StaticColor],"StaticColor");
  strcpy(nom_classe[StaticGray], "StaticGray");
*/

  InitFenetre();

#if defined(__WXMOTIF__)
  display     = (Display*) window->GetXDisplay();
  fenetre     = (Window) _drawing_window->GetClientXWindow();
#elif defined(__WXX11__)
  display     = (Display*) wxGlobalDisplay();
  fenetre     = (Window) _drawing_window->GetMainWindow();
#endif

  //  XGetWindowAttributes( display, fenetre, &w_attrib);

  CreateContext();



  aff_err("_pixmap_contexte OK \n");

  //  XSetWindowBackground( display, fenetre, 100);

  //----- Definition de la palette
  Si _palette == NULL Alors
    aff_err("new palette \n");
    _palette = new CPalette(_drawing_window);
    _palette_allouee = true;
    aff_err("new palette OK \n");
  FinSi

#if defined(__WXMOTIF__)
  XSetForeground( display, _pixmap_contexte,
		  ClasseCouleur((unsigned char)255,
                                (unsigned char)255,
                                (unsigned char)255).GetPixel());
#endif

  //  printf("window attributes : visual class %s\n",
  //	 nom_classe[w_attrib.visual->c_class]);
  //  printf("palette attributes : visual class %s\n",
  //	 nom_classe[_palette->_visual->c_class]);

  // Getting rid of pseudo color ...

  _fenetre_affichee = true;
  aff_err("AfficheFenetre() Fin\n");

} // AfficheFenetre()


//-------------------------------------------------------------------------
InrImage* FenetreDessin :: GetInrImage()
//                                   -----------
{
#if defined(__WXMOTIF__)
    XImage*   image;
    unsigned char   image_recuperee = false;
    InrImage* result;
    unsigned char *inpix;
    int x,y;
    ClasseCouleur color;

  image = RecupereImage();
  image_recuperee = true;

  // write the inrimage
  result=new InrImage(image->width,image->height,1,WT_RGB);

  inpix = (unsigned char*) image->data;

  result->InitBuffer();

  for (y=0; y< image->height; y++) {
    for (x=0; x<image->width ; x++) {
      color.Set(XGetPixel(image,x,y));
      result->VectFixeValeurs(  color.Red(),
                                color.Green(),
                                color.Blue());
      inpix++;
      result->IncBuffer();
    }
  }

  Si image_recuperee AlorsFait XDestroyImage(image);

  return result;
#else
  cerr << "FenetreDessin::GetInrImage() \t not yet available in this platform :( ..." << endl;
  return NULL;
#endif
} // GetInrImage()


#if defined(__MOTIF__)
//---------------------------------------------------------------------
XImage* FenetreDessin :: RecupereImage( )
//                                 -------------
{

   
    unsigned long plane_mask= 0xffffffff;

//  plane_mask = 255*(255+255)*255+255;

  return XGetImage( display, _ecran_dessin, 0, 0, _largeur, _hauteur,
                      plane_mask, ZPixmap);

} // RecupereImage()
#endif


//----------------------------------------------------------
void FenetreDessin::FixeCouleurFond( 
//                  ---------------
                        const ClasseCouleur& couleur)
{

#if defined(__WXMOTIF__)
  XSetBackground( display, contexte, couleur.GetPixel());
#endif

} // FixeCouleurFond()



//---------------------------------------------------------------------
// Recupere les dimension de la fenetre
//
void FenetreDessin :: Recupere_fenetre_dimensions( int* l, 
int* h)
//                              ---------------------------
{
   int largeur;
   int hauteur;

   largeur = this->GetSize().GetWidth();
   hauteur = this->GetSize().GetHeight();

  *l = largeur;
  *h = hauteur;

} // Recupere_fenetre_dimensions()


//---------------------------------------------------------------------
// Fixe les dimension de la fenetre
//
void FenetreDessin :: Fixe_fenetre_dimensions( int l, int h,
//                              -----------------------
							 unsigned char parent)
{

  this->SetSize(l,h);

} // Fixe_fenetre_dimensions()


//---------------------------------------------------------------------
// Recupere la position  de la fenetre
//
void FenetreDessin :: Recupere_fenetre_position( int* pos_x, int* pos_y)
//                              -------------------------
{
  this->GetPosition(pos_x,pos_y);

} // Recupere_fenetre_position()


//---------------------------------------------------------------------
// Fixe la position de la fenetre
//
void FenetreDessin :: Fixe_fenetre_position( int pos_x, int pos_y)
//                              ---------------------
{
  this->Move(pos_x,pos_y);

} // Fixe_fenetre_position()


//---------------------------------------------------------------------
// Fixe la couleur de la r�ion de dessin.
//
void FenetreDessin :: Fixe_drawing_bg( const wxColour& couleur)
//                              ---------------
{
  _drawing_window->SetBackgroundColour(couleur);
} // Fixe_drawing_bg()


//---------------------------------------------------------------------
// Fixe les dimension de la region de dessin
//
void FenetreDessin :: Fixe_drawing_dimensions( int l, int h)
//                              -----------------------
{
  _drawing_window->SetSize(l,h);
} // Fixe_drawing_dimensions()




//-----------------------------------------------------------
void FenetreDessin::FixeCouleurRemplissage(
//                  ----------------------
                const ClasseCouleur& couleur)
{
  #if defined(__WXMOTIF__)
    XSetForeground( display, contexte, couleur.GetPixel());
  #else
    _current_brush->SetColour((wxColour)couleur);
    _memory_dc->SetBrush(*_current_brush);
  #endif
} // FixeCouleurRemplissage()


//-------------------------------------------------
void  FenetreDessin::FixeStyleRemplissage( const int& style)
{
  #if (wxCHECK_VERSION(2,9,0)) 
  _current_brush->SetStyle((wxBrushStyle)style);
  #else
  _current_brush->SetStyle(style);
  #endif
  _memory_dc->SetBrush(*_current_brush);
} // FixeStyleRemplissage


/*
//------------------------------------------------------------
void FenetreDessin::FixeCouleurTrait( 
//                  ----------------
      const ClasseCouleur& couleur)
{

#if defined(__WXMOTIF__)
  XSetForeground( display, contexte, couleur.GetPixel());
#else
  _current_pen->SetColour(couleur);
  _memory_dc->SetPen(*_current_pen);
#endif

} // FixeCouleurTrait()
*/


//------------------------------------------------------------
void FenetreDessin::FixeCouleurTrait(  const wxColour& couleur)
//                  ----------------
{
  #if defined(__WXMOTIF__)
    XSetForeground( display, contexte, couleur->GetPixel());
  #else
    _current_pen->SetColour(couleur);
    _memory_dc->SetPen(*_current_pen);
  #endif
} // FixeCouleurTrait()


//------------------------------------------------------------
void FenetreDessin::SetTextBg(  const wxColour& color)
//                  ---------
{
    _memory_dc->SetTextBackground(color);
} 


//------------------------------------------------------------
void FenetreDessin::SetTextFg(  const wxColour& color)
//                  ---------
{
    _memory_dc->SetTextForeground(color);
} 


//---------------------------------------------------------------------
void FenetreDessin ::  FixeParametresLigne( unsigned int largeur, 
//                               -------------------
                        int style, 
                        int extremites, 
                        int intersection)
{
  _current_pen->SetWidth(largeur);
  #if (wxCHECK_VERSION(2,9,0)) 
    if (style!=-1)
      _current_pen->SetStyle((wxPenStyle)style);
    if (extremites!=-1) 
      _current_pen->SetJoin((wxPenJoin)extremites);
  #else 
    if (style!=-1)
      _current_pen->SetStyle(style);
    if (extremites!=-1) 
      _current_pen->SetJoin(extremites);
  #endif
  _memory_dc->SetPen(*_current_pen);
} // FixeParametresLigne()




//---------------------------------------------------------------------
void FenetreDessin::DrawingAreaInit( )
//                  --------------
{
  if (GB_debug)
    cerr << "FenetreDessin::DrawingAreaInit( )" << endl;

  if (!this->IsShown()) {
    cout << "FenetreDessin::DrawingAreaInit( ) \t window not shown " << endl;
    return;
  }

  if (this->IsIconized()) {
    cout << "FenetreDessin::DrawingAreaInit( ) \t window is iconized " << endl;
    return;
  }

  // wx way
  scoped_ptr<wxBitmap> bitmap(new wxBitmap(  _largeur, 
                                              _hauteur,
                                              -1));
  swap(_bitmap,bitmap);
  scoped_ptr<wxMemoryDC> memory_dc(new wxMemoryDC);
  /*
  if (!memory_dc->IsOk()) {
    cerr  << "FenetreDessin::DrawingAreaInit( )"
          << "\t failed to create memory DC"
          << endl;
    return;
  }
  */
  swap(_memory_dc, memory_dc);
  _memory_dc->SelectObject(*_bitmap);
  _memory_dc->SetBackgroundMode(wxTRANSPARENT);
  scoped_ptr<wxBrush> current_brush(new wxBrush(
                             *wxBLACK, wxSOLID));
  swap(_current_brush,current_brush);
  scoped_ptr<wxPen> current_pen(new wxPen( *wxBLACK,
                                 1,
                                 wxSOLID));
  swap(_current_pen,current_pen);

  _memory_dc->SetBrush(*_current_brush);
  _memory_dc->SetPen  (*_current_pen);

  // Set font to avoid problems ...
  wxClientDC dc(_drawing_window);
  if (dc.IsOk())
    _memory_dc->SetFont(dc.GetFont());


} // DrawingAreaInit( )


//---------------------------------------------------------------------
void FenetreDessin::DrawingAreaDisplay( )
//                  ------------------
{
  if (_memory_dc) {

    wxClientDC dc(_drawing_window);
    if (dc.IsOk()) {
      //cout << "drawing bitmap " << endl;
      //dc.SetBackgroundMode(wxTRANSPARENT);
      //dc.DrawBitmap(*_bitmap,0,0,false);

      dc.Blit(0,0,
	      _memory_dc->GetSize().GetWidth(),
	      _memory_dc->GetSize().GetHeight(),
	      _memory_dc.get(),
	      0,0);

    } else 
      cerr  << "FenetreDessin::DrawingAreaDisplay( )\t"
            << "DC not OK" << endl;

  } else {
    cerr << "FenetreDessin::DrawingAreaDisplay( )"
          << "\t context not allocated" << endl;
  }


} // DrawingAreaDisplay( )


//---------------------------------------------------------------------
void FenetreDessin :: DrawingAreaClear( )
//                    -------------
{

#if defined(__WXMOTIF__)

    Pixel   bg;

  Si Non(_pixmap_alloue) Alors
    fprintf(stderr,"FenetreDessin::DrawingAreaClear() \t Pixmap not allocated \n");
    return;
  FinSi
  bg = _drawing_window->GetBackgroundColour().GetPixel();
  XSetForeground( display, _pixmap_contexte, bg);
  XFillRectangle( display, 
		  _pixmap, 
		  _pixmap_contexte, 
		  0, 0, _largeur, _hauteur);
#else
  if (_memory_dc) {
    //_memory_dc->SelectObject(*_bitmap);
    _memory_dc->SetBackground(_drawing_window->GetBackgroundColour());
    _memory_dc->Clear();
  }
#endif

} // DrawingAreaClear( )


//---------------------------------------------------------------------
void FenetreDessin :: DrawingAreaFree( )
//                    ------------
{

} // DrawingAreaFree( )


//---------------------------------------------------------------------
void FenetreDessin :: FixeFonctionDessin( int fonction)
//                    ------------------
{
#if defined(__WXMOTIF__)
  XSetFunction(	display, contexte, fonction);
#endif
} // FixeFonctionDessin( )


//---------------------------------------------------------------------
void FenetreDessin::Ligne( int x1, int y1, int x2, int y2)
//                  -----
{
  _memory_dc->DrawLine(x1, y1, x2, y2);
} // Ligne()


//---------------------------------------------------------------------
void FenetreDessin::Cercle( int x1, int y1, int rayon)
//                              ------
{
#if defined(__WXMOTIF__)
  XDrawArc( display, _ecran_dessin, contexte, x1-rayon, y1-rayon, 
	    2*rayon, 2*rayon, 0, 360*64);
#else
  _memory_dc->DrawCircle(x1,y1, rayon);
#endif
} // Cercle()


//---------------------------------------------------------------------
void FenetreDessin :: Ellipse( int x1, int y1, 
//                              ------
					 int r1, int r2)
{

#if defined(__WXMOTIF__)
  XDrawArc( display, _ecran_dessin, contexte, x1-r1, y1-r2, 
	    2*r1, 2*r2, 0, 360*64);
#endif

} // Ellipse()


//---------------------------------------------------------------------
void FenetreDessin :: RemplitEllipse( int x1, int y1, 
//                              --------------
					 int r1, int r2)
{

#if defined(__WXMOTIF__)
  XFillArc( display, _ecran_dessin, contexte, x1-r1, y1-r2, 
	    2*r1, 2*r2, 0, 360*64);
#endif

} // RemplitEllipse()


//---------------------------------------------------------------------
void FenetreDessin :: Rectangle( int x1, int y1, int x2, int y2)
//                              ---------
{

  int aux;

  Si x1 > x2 Alors
    aux = x1;
    x1 = x2;
    x2 = aux;
  FinSi

  Si y1 > y2 Alors
    aux = y1;
    y1 = y2;
    y2 = aux;
  FinSi

#if defined(__WXMOTIF__)
  XDrawRectangle( display, _ecran_dessin, contexte, x1, y1, x2-x1, y2-y1);
#else
  _memory_dc->DrawRectangle(x1, y1, x2-x1, y2-y1);
#endif


} //Rectangle()


//---------------------------------------------------------------------
void FenetreDessin :: Point( int x1, int y1)
//                              -----
{

#if defined(__WXMOTIF__)
  XDrawPoint( display, _ecran_dessin, contexte, x1, y1);
#endif

} // Ligne()


//---------------------------------------------------------------------
void FenetreDessin :: Texte( int x, int y, const Chaine& chaine, unsigned char overwrite)
//                              -----
{
#if defined(__WXMOTIF__)
  Si overwrite Alors
    XFontStruct* font_str;
    int          dir;
    int          ascent;
    int          descent;
    XCharStruct  xchar;
    Pixel        bg;
    XGCValues    xgc;

    font_str = XQueryFont(display, XGContextFromGC(contexte));

    XTextExtents(font_str,
		 (char*) chaine,
		 strlen((char*) chaine),
		 &dir,
		 &ascent,
		 &descent,
		 &xchar);

  bg = _drawing_window->GetBackgroundColour().GetPixel();

    XGetGCValues(display,contexte,GCForeground,&xgc);
    XSetForeground( display, contexte, bg);
    XFillRectangle(display, _ecran_dessin, contexte,
		   x+xchar.lbearing-1,
		   y-xchar.ascent-1,
		   xchar.width+2,
		   xchar.ascent+xchar.descent+2);
    XChangeGC(display,contexte,GCForeground,&xgc);

  FinSi

  XDrawString( display, _ecran_dessin, contexte, x, y, 
	       (char*) chaine,  chaine.length());
#else
  _memory_dc->DrawText(wxString((const char*) chaine,wxConvUTF8),x,y);
#endif

} // Texte()


#if defined(__WXMOTIF__)
//---------------------------------------------------------------------
void FenetreDessin :: Polygone( int nb_pts, XPoint* points)
//                              --------
{

  XFillPolygon( display, _ecran_dessin, contexte, points, nb_pts, 
                Complex, CoordModeOrigin);

} // Polygone()
#endif


#if defined(__WXMOTIF__)
//---------------------------------------------------------------------
void FenetreDessin::PlaceImage( int pos_x, int pos_y, XImage* ximage )
//                  ---------
{

 XPutImage( display, _ecran_dessin, contexte,
	       ximage, 0, 0, pos_x, pos_y, ximage->width, ximage->height );

} // PlaceImage()
#endif


//---------------------------------------------------------------------
void  FenetreDessin::PutSlice(  int pos_x, int pos_y, 
//                   --------
                                const wxImage_ptr& slice)
{
  if (!_bitmap) {
    cerr << "FenetreDessin::PutSlice() _bitmap not allocated " << endl;
    return;
  }
  if (!slice.use_count()) {
    cerr << "FenetreDessin::PutSlice() slice not allocated " << endl;
    return;
  }
  //_memory_dc->SelectObject(*_bitmap);
  wxBitmap bitmap(*slice);
  _memory_dc->DrawBitmap( bitmap,
                          (wxCoord)pos_x,
                          (wxCoord)pos_y );
  // Draw a rectangle outside?
  FixeCouleurTrait( *wxBLACK);
  FixeStyleRemplissage(wxTRANSPARENT);
  FixeParametresLigne(1,wxSOLID);
  Rectangle((wxCoord)pos_x,(wxCoord)pos_y,
            (wxCoord)pos_x+bitmap.GetWidth(),
            (wxCoord)pos_y+bitmap.GetHeight());
  FixeStyleRemplissage(wxSOLID);
  

} // PutSlice()


//---------------------------------------------------------------------
void FenetreDessin::EffaceEcran( unsigned char expose)
//                              -----------
{
  if (GB_debug) cerr << "++++++  FenetreDessin::EffaceEcran +++++++++" << endl;
//  _drawing_window->ClearBackground( );

} // EffaceEcran()


//---------------------------------------------------------------------
void FenetreDessin :: EffaceRegion( int h, int g,
//                              ------------
			int b, int d, unsigned char expose)
{

/* Obsolete
  XClearArea(  display, fenetre,
                 h, g, b, d,
                 expose);
*/

} // EffaceRegion()


//---------------------------------------------------------------------
void FenetreDessin::CloseWindow()
//   -------------
{ 
  if (GB_debug) fprintf(stderr,"FenetreDessin::CloseWindow() \n");
  Si CloseFunction != NULL Alors
    if (GB_debug) cerr << "calling closing function " << endl;

    void (*func)( void*) = (void (*)( void*)) CloseFunction;
    func( (void*) CloseData);
  Sinon
    // Call destructor
    //this->~FenetreDessin();
    Close(true);
  FinSi
}


//-----------------------------------------------------------------------
void FenetreDessin::Paint( unsigned char affiche )
//                              -----
{
  if (!_memory_dc) DrawingAreaInit( );

} // Paint()


//-----------------------------------------------------------------------
void FenetreDessin::ReDimensionne()
//                  -------------
{
  DrawingAreaInit( );
  Paint();
} // ReDimensionne()


//-----------------------------------------------------------------------
void FenetreDessin::OnClose(wxCloseEvent& event)
{

  if (GB_debug)
    fprintf(stderr,"FenetreDessin::OnClose\n");

    if ( event.CanVeto()  )
    {
      // Check if not already displaying a message
      // to avoid problems
      wxMessageDialog dialog( 
        this,
        _T("Are you sure that you want to close this window ?"),
        _T("Confirmation"), 
         wxNO_DEFAULT
        |wxYES_NO
        |wxCANCEL
        |wxICON_INFORMATION
        );

        switch ( dialog.ShowModal() )
        {
        case wxID_NO:
        case wxID_CANCEL:
            event.Veto();
            return;

        default:;
        }

    }

//  event.Veto();
  CloseWindow();

  if (GB_debug)
    fprintf(stderr,"FenetreDessin::OnClose end\n");
}
