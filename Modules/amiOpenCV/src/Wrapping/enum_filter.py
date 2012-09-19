

# Filtering the enumeration based on the name of the keys
def CheckEnum(enum_name,context_name,enumkeys):
  # OK if global context and name starts with CV
  # or context is cv
  
  ok = (context_name=="cv") or ((context_name=="::")and(enumkeys[0].startswith("CV_")))
  if ok:
    print "Accepted enum {0}  {1} :  {2}".format(context_name,enum_name,enumkeys)
  #else:
    #print "Rejected enum {0}  {1} :  ".format(context_name,enum_name)
  return ok
