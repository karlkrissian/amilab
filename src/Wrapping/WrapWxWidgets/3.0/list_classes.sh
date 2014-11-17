ls -l wrap_wx*.h | gawk  '{ match(, /wrap_(.*)\.h/, arr); print arr[1] };'
