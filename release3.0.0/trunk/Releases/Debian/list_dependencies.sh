#
# list the dependencies of the given binary as argument for debian package creation
#

dpkg -S `objdump -p $1  | grep NEEDED | awk '{ printf("%s ", $2) }'` \
  | awk 'BEGIN {FS=":"} ; {print $1}'  | sort -u \
  | awk ' {printf(" %s ",$1)}' | sed "s/  /, /g"
