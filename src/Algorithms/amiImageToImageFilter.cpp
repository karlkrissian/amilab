//
// C++ Implementation: ami::ImageToImageFilter
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "amiImageToImageFilter.h"
#include <pthread.h>
#include <iostream>


namespace ami {

template <class T>
struct thread_info {
    int   thread_id;            /* number of current thread */
    int   total_threads;        /* number of threads */
    long* points_processed;     /* number of pixels/voxels already processed */
    T* _this;         /* pointer to the class instance */
};


void ImageToImageFilter::Init()
{
  
  InrImage::ptr in = params.GetInput();
  int nt = params.GetNumberOfThreads();

  if (in.get()) {
    extenttype extent(params.GetOutputExtent());
#define SPLIT_Z_FIRST
#ifdef SPLIT_Z_FIRST
    // Set which dimension to split
    int splitaxis=2;
    while ( (extent.GetSize(splitaxis)<nt)&&
            (splitaxis>=0))
      splitaxis--;
#else
    // Set which dimension to split
    int splitaxis=0;
    while ( (extent.GetSize(splitaxis)<nt)&&
            (splitaxis<=2))
      splitaxis++;
#endif

    if (extent.GetSize(splitaxis)<nt) {
      // Change the number of threads to the bigger axis size
      splitaxis = 2;
      if (extent.GetSize(splitaxis)<extent.GetSize(1)) 
        splitaxis = 1;
      if (extent.GetSize(splitaxis)<extent.GetSize(0)) 
        splitaxis = 0;
      params.SetNumberOfThreads(extent.GetSize(splitaxis));
    }

    int axis_size   = extent.GetSize(splitaxis);
    double thread_size = ((double) axis_size)/nt;
    int minpos = extent.GetMin(splitaxis);
    for(int i=0;i<nt;i++) {
      int extmin = round(i*thread_size);
      int extmax = round((i+1)*thread_size-1);
      // need to add the minimal position in splitaxis here !!!
      extent.SetMinMax(splitaxis,minpos+extmin,minpos+extmax);
      extents.push_back(extent);
    }
  }
}


//------------------------------------------------------------------
void* ImageToImageFilter::Process_thread(void* threadarg)
{
  // Get the arguments from threadarg
  thread_info<ImageToImageFilter>* args = (thread_info<ImageToImageFilter>*) threadarg;

  int   thread_id     = args->thread_id;
//  int   total_threads = args->total_threads;

  ImageToImageFilter* _this = args->_this;

  //std::cout  << " thread begin" << thread_id << std::endl;
  _this->Process(thread_id);

//  std::cout  << " thread end" << thread_id << std::endl;
  pthread_exit(NULL);
  return(NULL);

} // ImageToImageFilter::Process_thread()


//------------------------------------------------------------------
void ImageToImageFilter::Run_multithreads()
{
  if (params.GetNumberOfThreads()==1) {
    // no thread here ...
    Process();
  } else {
    // num_threads
    thread_info<ImageToImageFilter>* thread_info_array;
    int i;
    pthread_t* threads;
    pthread_attr_t attr;
    int rc,status;
    int num_threads = params.GetNumberOfThreads();

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    thread_info_array = new thread_info<ImageToImageFilter>[num_threads];

    threads     = new pthread_t[num_threads];
    for (i=0;i<num_threads;i++) {
      thread_info_array[i].thread_id      = i;
      thread_info_array[i].total_threads  = num_threads;
      thread_info_array[i]._this          = this;

      rc = pthread_create(&threads[i], &attr,
                          Process_thread,
                          (void *) &thread_info_array[i]);
      if (rc) {
        std::cerr  << __func__ 
              << " \t ERROR; return code from pthread_create()"
              << "is " <<  rc << std::endl;
        return;
      }
    } // end for
  
    // Free attribute and wait for the other threads 
    pthread_attr_destroy(&attr);
    for(i=0; i<num_threads; i++)
    {
        rc = (int) pthread_join((pthread_t)threads[i], (void **)&status);
        if (rc)
          std::cerr  << __func__ 
                <<  "\t ERROR; return code from pthread_join()"
                <<  "is " <<  rc << std::endl;
    }
  
    delete [] thread_info_array;
    delete [] threads;
  } // else if  numthread==1
} // ImageToImageFilter::Process_multithreads()


//------------------------------------------------------------------
void ImageToImageFilter::Run()
{
  //std::cout << "ImageToImageFilter::Run() Begin" << std::endl;
  
  //std::cout << "Init()" << std::endl;
  Init();
  //std::cout << "Run_multithreads()" << std::endl;
  Run_multithreads();
  //std::cout << "Close()" << std::endl;
  Close();
} // ImageToImageFilter::Run()

} // end namespace ami

