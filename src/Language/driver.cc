
/*
  taken from http://idlebox.net/2007/flex-bison-cpp-example/
  Thanks to the authors:
    Timo Bingmann
  and http://ioctl.org/jan/bison/
*/

// $Id: driver.cc 39 2008-08-03 10:07:15Z tb $
/** \file driver.cc Implementation of the example::Driver class. */

#include <fstream>
#include <sstream>

#include "driver.h"
#include "scanner.h"

namespace example {

Driver::Driver()
    : trace_scanning(false),
      trace_parsing(false)
{
}

bool Driver::parse_stream(std::istream& in, const std::string& sname)
{
    streamname = sname;

    Scanner scanner(&in);
    scanner.set_debug(trace_scanning);
    this->lexer = &scanner;

    Parser parser(*this);
    parser.set_debug_level(trace_parsing);
    return (parser.parse() == 0);
}

bool Driver::parse_file(const std::string &filename)
{
    std::ifstream in(filename.c_str());
    if (!in.good()) return false;
    return parse_stream(in, filename);
}

bool Driver::parse_string(const std::string &input, const std::string& sname)
{
    std::istringstream iss(input);
    return parse_stream(iss, sname);
}

void Driver::error(const class location& l,
		   const std::string& m)
{
    std::cerr << l << ": " << m << std::endl;
}

void Driver::error(const std::string& m)
{
    std::cerr << m << std::endl;
}


void Driver::yyip_switch_to_block( const AmiInstructionBlock_ptr& b )
{
/* to do ...
  yyiplineno = b->GetStartingLine();
  yyip_switch_to_string(b->GetBody().c_str());
*/
}


void Driver::yyip_call_function( const AMIFunction_ptr& f)
{
/* to do ...
  int    previous_lineno   = yyiplineno;
  string previous_filename = GB_current_file;

  // Call the function
  GB_current_file = f->GetFileName();
  yyip_switch_to_block(f->GetBody());
  yyip_parse();
  yyip_popup_buffer();

  // Restore position
  yyiplineno = previous_lineno;
  GB_current_file = previous_filename;

  // Continue parsing
  //continue_parse();
*/
}


} // namespace example
