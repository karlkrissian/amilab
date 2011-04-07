
scriptname=$1

if [[ -d ${scriptname} ]]
then
  echo "The directory ${scriptname} already exists !!"
else
  mkdir ${scriptname}
  cp -r ../ScriptExample/* ${scriptname}
  rm -Rf ${scriptname}/Doc/.svn

  for f in `find ${scriptname}/. -name "*.*" -type f`
  do
    #echo $f
    newname=`echo $f  | sed -e 's/ScriptExample/'${scriptname}'/g'`
    #echo "newname = $newname"
    if [[ $f != $newname ]]
    then
    sed -e 's/ScriptExample/'${scriptname}'/g' $f > ${newname}
    rm $f
    else
    sed -e 's/ScriptExample/'${scriptname}'/g' $f > ${newname}_tmp
    mv ${newname}_tmp ${newname}
    fi
  done

  echo " ami.MainFrame.AddToMenu(\"&PDI\",category,\"&${scriptname}\",  dir+\"${scriptname}/${scriptname}Gui\")" >> tmp
  echo "" >> tmp
  cat Add2Menu.amil tmp > Add2Menu.amil.new
  rm tmp
  mv Add2Menu.amil Add2Menu.amil.bak
  mv Add2Menu.amil.new Add2Menu.amil

fi



