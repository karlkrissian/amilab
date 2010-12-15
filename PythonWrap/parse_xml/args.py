#
# Defining the command line arguments
#

import argparse

arg_parser = argparse.ArgumentParser(description='Wrapping g++ code (gccxml output)  in AMILab.')

arg_parser.add_argument('xmlfilename',                      \
  help='name of xml file generated by gccxml' )

#arg_parser.add_argument('headerfile',                       help='name of file to include, used by gccxml' )

arg_parser.add_argument('--classes', nargs='*',  default=[],  \
  help='name of the class(es) to wrap' )

arg_parser.add_argument('--functions', nargs='*', default=[],  \
  help='name of the function(s) to wrap' )

arg_parser.add_argument('--methodpointers', nargs='*', default=[], \
  help='name of the method pointers to wrap' )

arg_parser.add_argument('--wrap_includes', nargs='*',  default=[],  \
  help='directories where are the available wrapped classes' )

arg_parser.add_argument('--outputdir', default='wrap/',             \
  help='output directory' )

arg_parser.add_argument('-r',       action='store_true',    \
  help='Recursively wrap needed classes')

arg_parser.add_argument('--overwrite',action='store_true',  \
  help='Overwrite existing wrapped classes')

arg_parser.add_argument('--templates',action='store_true',  \
  help='Wrap template class instances')

arg_parser.add_argument('--templatefile_dir', default=".",  \
  help='Directory containing the template files (wrap_class.h.in, etc ...)')

arg_parser.add_argument('-q',       action='store_true',    help='Quiet mode')

arg_parser.add_argument('--filter', default=r'.*',          help='Recursively wrap needed classes')

arg_parser.add_argument('--constructor', default='',        help='Specify the method (static) used for the constructor if it is not the standard one.')

arg_parser.add_argument('--libname',                        help='name of the library to wrap (without spaces or special characters)')

arg_parser.add_argument('--update', action='store_true',   \
  help='re-generate all currently wrapped classes')

arg_parser.add_argument('--max', type=int,default=200,   \
  help='maximum number of files generated')

arg_parser.add_argument('-gccxml',       action='store_true',    \
  help='Try to generate the xml for the library')

# Parse can it work??
val = arg_parser.parse_args()

# works??
#from args import *

print "recursive:",val.r
print "overwrite:",val.overwrite
print "library name:",val.libname
