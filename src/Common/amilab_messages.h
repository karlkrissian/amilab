//
// C++ Interface: amilab_messages
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _amilab_messages_h_
#define _amilab_messages_h_

#define FILE_ERROR( m) \
  if (GB_debug)  {\
    std::cerr << "Error \t"; \
    std::cerr << "file: " << __FILE__    << std::endl; \
    std::cerr << "      \t" << __func__ << std::endl; \
    std::cerr << "      \t" << m        << std::endl; \
  }

#define CLASS_ERROR( m) \
  if (GB_debug)  {\
    std::cerr << "Error \t" \
              << this->get_name() << "::" \
              << __func__  << "(), line " << __LINE__ << "\t"\
              << m        << std::endl; \
  }

#define CLASS_MESSAGE(m) \
  if ((GB_verbose) || (GB_debug)) { \
    std::cerr << "Info \t" \
              << this->get_name() << "::" \
              << __func__ << "()\t"  \
              << m << std::endl; \
  }

extern unsigned char GB_debug;
extern unsigned char GB_verbose;

#endif //  _amilab_messages_h_
