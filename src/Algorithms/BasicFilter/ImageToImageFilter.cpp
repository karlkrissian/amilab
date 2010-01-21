//
// C++ Implementation: ImageToImageFilter
//
// Description: 
//
//
// Author:  <Karl Krissian>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#include "ImageToImageFilter.h"
#include <pthread.h>

template <class T>
struct thread_info {
    int   thread_id;            /* number of current thread */
    int   total_threads;        /* number of threads */
    long* points_processed;     /* number of pixels/voxels already processed */
    T* _this;         /* pointer to the class instance */
};



//------------------------------------------------------------------
void* ImageToImageFilter::Process_thread(void* threadarg)
{
  // Get the arguments from threadarg
  thread_info<ImageToImageFilter>* args = (thread_info<ImageToImageFilter>*) threadarg;

  int   thread_id     = args->thread_id;
  int   total_threads = args->total_threads;

  ImageToImageFilter* _this = args->_this;

  //cout  << " thread " << thread_id 
  _this->Process(thread_id);

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
        cerr  << __func__ 
              << " \t ERROR; return code from pthread_create()"
              << "is " <<  rc << endl;
        return;
      }
    } // end for
  
    // Free attribute and wait for the other threads 
    pthread_attr_destroy(&attr);
    for(i=0; i<num_threads; i++)
    {
        rc = (int) pthread_join((pthread_t)threads[i], (void **)&status);
        if (rc)
          cerr  << __func__ 
                <<  "\t ERROR; return code from pthread_join()"
                <<  "is " <<  rc << endl;
    }
  
    delete [] thread_info_array;
    delete [] threads;
  } // else if  numthread==1
} // ImageToImageFilter::Process_multithreads()


//------------------------------------------------------------------
void ImageToImageFilter::Run()
{
  Init();
  Run_multithreads();
  Close();
} // ImageToImageFilter::Run()

