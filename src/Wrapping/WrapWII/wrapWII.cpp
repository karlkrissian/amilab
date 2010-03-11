//
// C++ Implementation: wrapAMIFluid
//
// Description: 
//
//
// Author: Karl Krissian,,, <karl@UBUNTU-KARL>, (C) 2006
//
// Copyright: See COPYING file that comes with this distribution
//
//

//#define _USE_WII_
#ifdef _USE_WII_

#include <pthread.h>

extern "C" {
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "/usr/local/include/wiiuse/wiiuse.h"
}

#endif // _USE_WII_



#include "VarContexts.hpp"
#include "wrapfunctions.hpp" 
#include "wrapWII.h"

extern VarContexts  Vars;

#ifdef _USE_WII_

// no thread safe ???
static wiimote** wiimotes;
static struct wiimote_t wiimote_info;
static int wii_btns;
static vec3b_t wii_accel;
static orient_t wii_orient;
static gforce_t wii_gforce;
static unsigned char wiimote_pollevents;
static int event_counter=0;

/**
 *  @brief Callback that handles an event.
 *
 *  @param wm   Pointer to a wiimote_t structure.
 *  @param btns   What buttons are currently pressed.  They are OR'ed together.
 *  @param accel  Acceleration of the device along each axis.
 *          This is the raw data reported by the wiimote.
 *  @param orient Orientation (roll, pitch, yaw) of the device.
 *  @param gforce Pull of gravity on each axis of the device (measured in gravity units).
 *
 *  This function is called automatically by the wiiuse library when an
 *  event occurs on the specified wiimote.
 */
void handle_event(struct wiimote_t* wm, int btns, vec3b_t accel, orient_t orient, gforce_t gforce) {
//  printf("\n\n--- EVENT [wiimote id %i] ---\n", wm->unid);


  if (btns) {
/*
    // if a button is pressed, report it 
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_A))   printf("A pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_B))   printf("B pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_UP))  printf("UP pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_DOWN))  printf("DOWN pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_LEFT))  printf("LEFT pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_RIGHT)) printf("RIGHT pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_MINUS)) printf("MINUS pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_PLUS))  printf("PLUS pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_ONE)) printf("ONE pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_TWO)) printf("TWO pressed\n");
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_HOME))  printf("HOME pressed\n");
*/
    //
     // Pressing minus will tell the wiimote we are no longer interested in movement.
     // This is useful because it saves battery power.
     //
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_MINUS))
      wiimote_motion_sensing(wm, 0);

    //
     // Pressing plus will tell the wiimote we are interested in movement.
    
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_PLUS))
      wiimote_motion_sensing(wm, 1);

    //
     // Pressing B will toggle the rumble
     //
     // if B is pressed but is not held, toggle the rumble
     //
    if (IS_PRESSED(btns, WIIMOTE_BUTTON_B) && !IS_HELD(wm, WIIMOTE_BUTTON_B))
      wiimote_toggle_rumble(wm);
  }


/*
  printf("Zero:\tX=%i\tY=%i\tZ=%i\n", wm->cal_zero.x, wm->cal_zero.y, wm->cal_zero.z);
  printf("  1g:\tX=%i\tY=%i\tZ=%i\n", wm->cal_g.x, wm->cal_g.y, wm->cal_g.z);
  printf(" Raw:\tX=%i\tY=%i\tZ=%i\n", accel.x, accel.y, accel.z);

  printf("gforce x: %f\n", gforce.x);
  printf("gforce y: %f\n", gforce.y);
  printf("gforce z: %f\n", gforce.z);

  printf("roll  = %f\n", orient.roll);
  printf("pitch = %f\n", orient.pitch);
  printf("yaw   = %f\n", orient.yaw);
*/
  wii_btns = btns;
  wii_accel  = accel;
  wii_gforce = gforce;
  wii_orient = orient;
}


/**
 *  @brief Callback that handles a read event.
 *
 *  @param wm   Pointer to a wiimote_t structure.
 *  @param data   Pointer to the filled data block.
 *  @param len    Length in bytes of the data block.
 *
 *  This function is called automatically by the wiiuse library when
 *  the wiimote has returned the full data requested by a previous
 *  call to wiimote_read_data().
 *
 *  You can read data on the wiimote, such as Mii data, if
 *  you know the offset address and the length.
 *
 *  The \a data pointer was specified on the call to wiimote_read_data().
 *  At the time of this function being called, it is not safe to deallocate
 *  this buffer.
 */
void handle_read(struct wiimote_t* wm, byte* data, unsigned short len) {
  printf("\n\n--- DATA READ [wiimote id %i] ---\n", wm->unid);
  printf("finished read of size %i\n", len);
  int i = 0;
  for (; i < len; ++i) {
    if (!(i%16))
      printf("\n");
    printf("%x ", data[i]);
  }
  printf("\n\n");
}


/**
 *  @brief Callback that handles a controller status event.
 *
 *  @param wm       Pointer to a wiimote_t structure.
 *  @param attachment   Is there an attachment? (1 for yes, 0 for no)
 *  @param speaker      Is the speaker enabled? (1 for yes, 0 for no)
 *  @param ir       Is the IR support enabled? (1 for yes, 0 for no)
 *  @param led        What LEDs are lit.
 *  @param battery_level  Battery level, between 0.0 (0%) and 1.0 (100%).
 *
 *  This occurs when either the controller status changed
 *  or the controller status was requested explicitly by
 *  wiimote_status().
 *
 *  One reason the status can change is if the nunchuk was
 *  inserted or removed from the expansion port.
 */
void handle_ctrl_status(struct wiimote_t* wm, int attachment, int speaker, int ir, int led[4], float battery_level) {
  printf("\n\n--- CONTROLLER STATUS [wiimote id %i] ---\n", wm->unid);

  printf("attachment:      %i\n", attachment);
  printf("speaker:         %i\n", speaker);
  printf("ir:              %i\n", ir);
  printf("led 1:           %i\n", led[0]);
  printf("led 2:           %i\n", led[1]);
  printf("led 3:           %i\n", led[2]);
  printf("led 4:           %i\n", led[3]);
  printf("battery:         %f %%\n", battery_level);
}


/**
 *  @brief Callback that handles a disconnection event.
 *
 *  @param wm       Pointer to a wiimote_t structure.
 *
 *  This can happen if the POWER button is pressed, or
 *  if the connection is interrupted.
 */
void handle_disconnect(wiimote* wm) {
  printf("\n\n--- DISCONNECTED [wiimote id %i] ---\n", wm->unid);
}


#define WIIMOTE_ID_1    1
#define WIIMOTE_ID_2    2



//---------------------------------------------------------
void AddWrapWII(){


  ADDVAR_PROC( WII_start);
  ADDVAR_PROC( WII_stop);
  ADDVAR_PROC( WII_getmotion);
  ADDVAR_PROC( WII_initcounter);
  ADDVAR_PROC( WII_printcounter);
  ADDVAR_PROC( WII_eventloop );
  ADDVAR_PROC( WII_GetRoll );
  ADDVAR_PROC( WII_GetPitch );
  ADDVAR_PROC( WII_GetGForceX );
  ADDVAR_PROC( WII_GetGForceY );
  ADDVAR_PROC( WII_GetGForceZ );
  ADDVAR_PROC( WII_GetButtons );
  ADDVAR_PROC( WII_GetEventCounter );
  ADDVAR_PROC( WII_SetMotionSensing );

}

void WII_start(ParamList*)
{
/*
  char functionname[] = "WII_start";
  char description[]=" \n\
    Detects the wiimote and initialize \n\
      ";
  char parameters[] =" \n\
      ";
*/
  /*
   *  Load the wiiuse library
   *
   *  This needs to be done before anything else can happen
   */
  float v = wiiuse_startup("/usr/local/lib/wii.so");
  printf("v = %f\n", v);
  if (!v) {
    fprintf(stderr, "Failed to load wiiuse library.\n");
    return;
  }

  /*
   *  Make a temp array of wiimote ids.
   *
   *  Here I only anticipate connecting up to
   *  two wiimotes.  Each wiimote connected
   *  will get one of these ids.
   */
  int ids[] = { WIIMOTE_ID_1 };

  /*
   *  Initialize an array of wiimote objects.
   *
   *  The first parameter is the number of wiimotes
   *  I want to create.  I only have two wiimotes
   *  so I'm limiting the test to just 2.
   *
   *  Then I get it the array of ids and a couple
   *  callback functions to invoke when something
   *  happens on one of the wiimotes.
   *
   *  handle_event gets called when a generic event occurs (button press, motion sensing, etc)
   *  handle_ctrl_status gets called when a response to a status request arrives (battery power, etc)
   *  handle_disconnect gets called when the wiimote disconnect (holding power button)
   */
  wiimotes =  wiimote_init(1, ids, handle_event, handle_ctrl_status, handle_disconnect);

  /*
   *  Find wiimote devices
   *
   *  Now we need to find some wiimotes.
   *  Give the function the wiimote array we created, and tell it there
   *  are 2 wiimotes we are interested in.
   *
   *  Set the timeout to be 5 seconds.
   *
   *  This will return the number of actual wiimotes that are in discovery mode.
   */
  printf("looking for wiimotes .. \n");
  int found = wiimote_find(wiimotes, 1, 5);
  printf("found = %d \n",found);
  if (!found)
    return;

  /*
   *  Connect to the wiimotes
   *
   *  Now that we found some wiimotes, connect to them.
   *  Give the function the wiimote array and the number
   *  of wiimote devices we found.
   *
   *  This will return the number of established connections to the found wiimotes.
   */
  int connected = wiimote_connect(wiimotes, 1);
  if (connected)
    printf("Connected to %i wiimotes (of %i found).\n", connected, found);
  else {
    printf("Failed to connect to any wiimote.\n");
    return; 
  }

  /*
   *  Now set the LEDs and rumble for a second so it's easy
   *  to tell which wiimotes are connected (just like the wii does).
   */
  wiimote_set_leds(wiimotes[0], WIIMOTE_LED_1 | WIIMOTE_LED_4);
  //  wiimote_set_leds(wiimotes[1], WIIMOTE_LED_2 | WIIMOTE_LED_3);
  wiimote_rumble(wiimotes[0], 1);
  //  wiimote_rumble(wiimotes[1], 1);
  usleep(200000);
  wiimote_rumble(wiimotes[0], 0);
  //  wiimote_rumble(wiimotes[1], 0);

  /*
   *  Maybe I'm interested in the battery power of the 0th
   *  wiimote.  This should be WIIMOTE_ID_1 but to be sure
   *  you can get the wiimote assoicated with WIIMOTE_ID_1
   *  using the wiimote_get_by_id() function.
   *
   *  A status request will return other things too, like
   *  if any extensions are plugged into the wiimote or
   *  what LEDs are lit.
   */
  wiimote_status(wiimotes[0]);
//  wiimote_motion_sensing(wiimotes[0], 1);

  /*
   *  This is the main loop
   *
   *  wiimote_poll() needs to be called with the wiimote array
   *  and the number of wiimote structures in that array
   *  (it doesn't matter if some of those wiimotes are not used
   *  or are not connected).
   *
   *  This function will invoke the callbacks set in wiimote_init()
   *  when the wiimote has things to report.
   */
//  while (1) {
//    wiimote_poll(wiimotes, 1);
//  }


//  return 0;

}

void WII_stop(ParamList*)
{
/*
  char functionname[] = "WII_stop";
  char description[]=" \n\
    Disconnect the wiimote \n\
      ";
  char parameters[] =" \n\
      ";
*/
  /*
   *  Disconnect the wiimotes
   */
  wiimote_disconnect(wiimotes[0]);
  //  wiimote_disconnect(wiimotes[1]);

  /*
   *  Unload the wiiuse library
   */
  wiiuse_shutdown();
}

void* wiimote_loop( void* threadarg)
{
  printf("Starting wiimote_loop \n");
  event_counter = 0;
   while (wiimote_pollevents) {
  if (wiimote_poll(wiimotes, 1)==1) event_counter++;
   }
   pthread_exit(NULL);
  printf("Ending wiimote_loop \n");
}



void WII_eventloop(ParamList* p)
{
/*  char functionname[] = "WII_eventloop";
  char description[]=" \n\
    Runs the wiimote_pool() wihtin a thread while the \n\
    static variable wiimote_pollevents is true \n\
      ";
  char parameters[] =" \n\
      ";
*/
//    int i,j,l;
    pthread_t* threads;
    pthread_attr_t attr;
    int rc,status;

    wiimote_pollevents=1;

    // computing the size of the displacement image
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    threads = (pthread_t*) malloc(sizeof(pthread_t));

    rc = pthread_create(&threads[0], &attr, wiimote_loop, NULL);
      if (rc) {
        printf("WII_eventlopp() \t ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
      }

   /* Free attribute and wait for the other threads */
   pthread_attr_destroy(&attr);
/*   rc = (int) pthread_join((pthread_t)threads[0], (void **)&status);
      if (rc)
      {
         printf("WII_eventlopp() \t ERROR; return code from pthread_join()  is %d\n", rc);
      }
//      printf("Completed join with thread %d status= %d\n",i, status);
   }
*/
}

void WII_getmotion(ParamList* p)
{
  char functionname[] = "WII_getmotion";
  char description[]=" \n\
    Gets the wiimote motion information \n\
      ";
  char parameters[] =" \n\
    - FLOAT IMAGE:      1D image of the parameters\n\
                - INTEGER NUMBER: number of calls to wiimote_polls \n\
    ";

  InrImage* im1;
  int num_calls=1;
  int n=0,c;

  if (!get_val_ptr_param<InrImage>(    im1,               p, n)) HelpAndReturn;
  if (!get_int_param(    num_calls,         p, n)) HelpAndReturn;

  for (c=0;c<num_calls;c++) wiimote_poll(wiimotes, 1);
  im1->InitBuffer();
  im1->FixeValeur(wii_accel.x);
  im1->IncBuffer();
  im1->FixeValeur(wii_accel.y);
  im1->IncBuffer();
  im1->FixeValeur(wii_accel.z);

  im1->IncBuffer();
  im1->FixeValeur(wii_gforce.x);
  im1->IncBuffer();
  im1->FixeValeur(wii_gforce.y);
  im1->IncBuffer();
  im1->FixeValeur(wii_gforce.z);

/*
  printf("roll  = %f\n", wii_orient.roll);
  printf("pitch = %f\n", wii_orient.pitch);
  printf("yaw   = %f\n", wii_orient.yaw);
*/

  im1->IncBuffer();
  im1->FixeValeur(wii_orient.roll);
  im1->IncBuffer();
  im1->FixeValeur(wii_orient.pitch);
  im1->IncBuffer();
  im1->FixeValeur(wii_orient.yaw);

}

void WII_GetRoll(ParamList* p) {
  char functionname[] = "WII_GetRoll";
  char description[]=" \n\
    gets the roll \n\
      ";
  char parameters[] =" \n\
      ";
  float* rollp;
  int n=0;

  if (!get_val_ptr_param<float>(    rollp,         p, n)) HelpAndReturn;

  *rollp = wii_orient.roll;
}

void WII_GetPitch(ParamList* p) {
  char functionname[] = "WII_GetPitch";
  char description[]=" \n\
    gets the pitch \n\
      ";
  char parameters[] =" \n\
      ";
  float* pitchp;
  int n=0;

  if (!get_val_ptr_param<float>(    pitchp,         p, n)) HelpAndReturn;

  *pitchp = wii_orient.pitch;
}

void WII_GetGForceX(ParamList* p) {
  char functionname[] = "WII_GetGForceX";
  char description[]=" \n\
    gets the X component of the force normalize to G \n\
      ";
  char parameters[] =" \n\
      ";
  float* gforce;
  int n=0;
  if (!get_val_ptr_param<float>(    gforce,         p, n)) HelpAndReturn;
  *gforce = wii_gforce.x;
}

void WII_GetGForceY(ParamList* p) {
  char functionname[] = "WII_GetGForceY";
  char description[]=" \n\
    gets the Y component of the force normalize to G \n\
      ";
  char parameters[] =" \n\
      ";
  float* gforce;
  int n=0;
  if (!get_val_ptr_param<float>(    gforce,         p, n)) HelpAndReturn;
  *gforce = wii_gforce.y;
}

void WII_GetGForceZ(ParamList* p) {
  char functionname[] = "WII_GetGForceZ";
  char description[]=" \n\
    gets the Z component of the force normalize to G \n\
      ";
  char parameters[] =" \n\
      ";
  float* gforce;
  int n=0;
  if (!get_val_ptr_param<float>(    gforce,         p, n)) HelpAndReturn;
  *gforce = wii_gforce.z;
}

void WII_GetButtons(ParamList* p) {
  char functionname[] = "WII_GetButtons";
  char description[]=" \n\
    gets the state of the buttons as an integer variable\n\
      ";
  char parameters[] =" \n\
      ";
  int* bts;
  int n=0;
  if (!get_val_ptr_param<int>(    bts,         p, n)) HelpAndReturn;
  *bts = wii_btns;
}

void WII_initcounter(ParamList*)
{
  char functionname[] = "WII_initcounter";
  char description[]=" \n\
    initializes event counter \n\
      ";
  char parameters[] =" \n\
      ";
  /*
   *  Disconnect the wiimotes
   */
//  wiimote_init_counter();
  //  wiimote_disconnect(wiimotes[1]);
}

void WII_printcounter(ParamList*)
{
  char functionname[] = "WII_initcounter";
  char description[]=" \n\
    prints event counter \n\
      ";
  char parameters[] =" \n\
      ";
  /*
   *  Disconnect the wiimotes
   */
//  printf(" WII event counter = %d \n",wiimote_get_counter());
  //  wiimote_disconnect(wiimotes[1]);
}


void WII_GetEventCounter(ParamList* p) 
{
  char functionname[] = "WII_GetEventCounter";
  char description[]=" \n\
    gets the value of the events counter\n\
      ";
  char parameters[] =" \n\
      ";
  float* counter;
  int n=0;
  if (!get_val_ptr_param<float>(    counter,         p, n)) HelpAndReturn;
  *counter = event_counter;
}


void WII_SetMotionSensing(ParamList* p)
{
  char functionname[] = "WII_SetMotionSensing";
  char description[]=" \n\
    Activate/Desactivate motion sensing\n\
      ";
  char parameters[] =" \n\
      ";
  float ms;
  int n=0;
  if (!get_val_param<float>(  ms,         p, n)) HelpAndReturn;
  wiimote_motion_sensing(wiimotes[0], ms);

}

#else

void AddWrapWII(){
}


#endif // _USE_WII_
