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
//  Karl Krissian
//  Brigham and Women's Hospital
//  Harvard Medical School
//  10/31/2001
//


#ifndef _MINHEAP_HPP
#define _MINHEAP_HPP


#include "style.hpp"
#include <iostream.h>
#include <stdio.h>

// Template ??
//

//----------------------------------------------------------------------
template < class T > class MinHeap
//                         -------
{

protected:

  int num_elts;
  int array_size;
  T*  array;

  void Resize(int size);

  int UpHeap(int pos);

  int DownHeap(int pos);

  void (*move_func)(const T&, int pos, void* data);
  void* move_data;

public:

  MinHeap( int arraysize = 2)
  {
    num_elts = 0;
    array_size = arraysize;
    if (array_size<1) array_size = 1;
    array = new T[array_size];
    move_func = NULL;
  }

  ~MinHeap()
  {
    delete [] array;
  }

  // This function acts when a value is moved or added in
  // the tree, and can allow to keep trace of the position
  // in the tree of each value.
  void SetMoveFunction(void (*func)(const T&, int pos, void* data),
		       void* movedata) 
  {
    move_func = func;
    move_data = movedata;
  }

  void SetValue( const T& t, int pos)
  {
    array[pos] = t;
    if (move_func != NULL) move_func(t,pos,move_data);
  }

  int Size() { return num_elts; }

  MinHeap<T>&  operator+=( T elt);

  T GetMin();

  T& operator[](int n);

  void ChangeValue(int n, const T& elt);

#if !(defined(_sgi_)) 
  friend ostream& operator << <>(ostream&, const MinHeap<T>& p);
#else
  friend ostream& operator << (ostream&, const MinHeap<T>& p);
#endif

};


//----------------------------------------------------------------------
// PROTECTED MEMBERS
//----------------------------------------------------------------------

template<class T> void MinHeap<T>::Resize( int size)
//                                 ------
{

    T*     new_array;
    int    new_nbelts,i=0;

  if (size < array_size) return;

  new_nbelts = size;
  new_array = new T [new_nbelts+1];

  Pour(i,0,new_nbelts)
    new_array[i] = array[i];
  FinPour

  delete [] array;

  array = new_array;
  array_size = new_nbelts;

} // Resize()

//--------------------------------------------------
template<class T> int MinHeap<T>::UpHeap( int pos)
//                                ------
{

    register int  up;
    T val;

    //    fprintf(stderr,"UpHeap(%d)\n",pos);

    if (pos<=1) return 1;

    val  = array[pos];
    up = pos>>1;

    while ((up>0)&&(val<array[up])) {
      SetValue(array[up],pos);
      pos = up;
      up >>= 1;
    }

    SetValue(val,pos);

    return pos;


} // UpHeap()


//--------------------------------------------------
template<class T> int MinHeap<T>::DownHeap( int pos)
//                                --------
{

    register int  down;
    T val;

    //    fprintf(stderr,"DownHeap(%d)\n",pos);

    val    = array[pos];
    down = pos<<1;

    if (down>num_elts) return pos;

    while (down<=num_elts) {

      if ((down<num_elts)&&(array[down+1]<array[down])) down++;

      if (val>array[down]) {
	SetValue(array[down],pos);
	pos = down;
	down <<= 1;
      }
      else break;

    }
    
    SetValue(val,pos);

    return pos;


} // DownHeap()

//----------------------------------------------------------------------
// PUBLIC MEMBERS
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//
//   Add an element to the heap
//  
template<class T>
MinHeap<T>& MinHeap<T> :: operator+=( T elt)
//                        ----------
{

    if ( num_elts >= array_size-1) Resize( 2*array_size );

    num_elts++;
    SetValue(elt,num_elts);

    // Put the new value at a correct emplacement
    //    DownHeap( UpHeap(num_elts));
    UpHeap(num_elts);

    return *this;

} // operator +=

//----------------------------------------------------------------------
//
//   Retreive the min (top) of the heap
//  
template<class T>
T MinHeap<T> :: GetMin()
//              ------
{
    T valmin;

    if (num_elts == 1) { num_elts=0; return array[1];}

    valmin = array[1];
    SetValue(array[num_elts],1);
    num_elts--;

    // Put the value at a correct emplacement
    DownHeap( 1);

    return valmin;

} // GetMin()


//--------------------------------------------------
template<class T>
T& MinHeap<T> :: operator[](int n)
//               ----------
{

  if ((n<1) || (n>num_elts))
       fprintf(stderr,
	       "MinHeap<T> operator[]\t Invalid Index... %d [0 %d]\n",
	       n, num_elts);
  else
      return array[n];
      
} // operator[]


//--------------------------------------------------
template<class T> void MinHeap<T>::ChangeValue( int pos, const T& elt)
//                                 -----------
{

  if (elt < array[pos]) {
    SetValue(elt,pos);
    UpHeap(pos);
  }
  else
    {
      SetValue(elt,pos);
      DownHeap(pos);
    }

  //  if (pos == UpHeap(pos)) DownHeap(pos);

} // UpDateValue()


//--------------------------------------------------
template<class T>
ostream& operator << (ostream& os, const MinHeap<T>& p)
//       -----------
{
  
    int i,j,n;

  os << "Heap =  \n ";
  i = 1;
  j = 1;
  while (j<=p.num_elts) {
    Pour(n,1,i)
      Si (j<=p.num_elts) Alors
        os << p.array[j];
        j++;
        Si n < i Alors
          os  << " - ";
        Sinon
          os   << std::endl;
        FinSi
      FinSi
    FinPour
    i <<=1;
  }

  os   << std::endl;
  return os;

} // operator << ( , const MinHeap<T>&)



#endif
