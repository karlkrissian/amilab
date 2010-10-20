#!/bin/bash

current_dir=`pwd`
basename_dir=`basename ${current_dir}`
dirname_dir=`dirname ${current_dir}`
amilab_dirlink=AMILab
echo "----"
echo "Creating symbolic link ${amilab_dirlink} --> ${basename_dir}"
echo "  in parent directory"
echo "----"
cd ..
if [[ -e ${amilab_dirlink} ]]
then 
  if [[ -h ${amilab_dirlink} ]]
  then
    rm -f ${amilab_dirlink}
  else
    echo "----"
    echo "Error: file ${amilab_dirlink} already exists and is not a symbolic link, aborting"
    echo "----"
    exit 1
  fi
fi

ln -s ${basename_dir} ${amilab_dirlink} 
cd ${amilab_dirlink}

amilab_dir=${dirname_dir}/${amilab_dirlink}

system=`uname -s`
if [[ ${system} == "Darwin" ]]
then
  libenv_var="DYLD_LIBRARY_PATH"
else
  libenv_var="LD_LIBRARY_PATH"
fi
echo "export ${libenv_var}=${amilab_dir}/libs/:\${LD_LIBRARY_PATH}" > amilab_env
echo "export AMI_SCRIPTS=${amilab_dir}/scripts/" >> amilab_env
echo "export AMI_HELP=${amilab_dir}/doc/" >> amilab_env
echo "export PATH=${amilab_dir}/bin/:\${PATH}" >> amilab_env

echo "----"
echo "The file amilab_env have been written in the current directory"
echo "It contains the following commands:"
echo
more amilab_env
echo
echo "----"
echo 
echo "You can add the line"
echo "     source ${amilab_dir}/amilab_env"
echo "to your ~/.bashrc file to have it automatically load into"
echo "your new shells."
echo "You can execute  'source amilab_env' to have it load now."
echo
echo "----"
