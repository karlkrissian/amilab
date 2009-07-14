//
// C++ Interface: IdentifierInfo
//
// Description: 
//
//
// Author: Karl Krissian <krissian@dis.ulpgc.es>, (C) 2009
//
// Copyright: See COPYING file that comes with this distribution
//
//

#ifndef _IdentifierInfo_h_
#define _IdentifierInfo_h_

#include "DefineClass.hpp"

/// Information carried out by identifiers
class IdentifierInfo {

  DEFINE_CLASS(IdentifierInfo)

protected:

  string name;
  /// if -1, use current context,
  /// otherwise use the specified context
  int creation_context;

public:
  IdentifierInfo( ): creation_context(-1) {}
  virtual ~IdentifierInfo() {}
  void SetName(const string& n) { name=n; }
  string GetName() const { return name; }
  void SetCreationContext(int c) { creation_context = c; }
  int  GetCreationContext() const { return creation_context; }
};

#endif //  _IdentifierInfo_h_
