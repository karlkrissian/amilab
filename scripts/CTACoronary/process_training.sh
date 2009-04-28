#!/bin/bash

minid=$1
maxid=$2
echo $#
if (( $# >= 3 ))
    then
    if (( $3 -eq "-rep" ))
	then
	recompute_rep=true
    else
	recompute_rep=false
    fi
fi

#maxmethod="multiline"

for ((id=$minid; id <= maxid ; id++)) 
do
  idstring=$(printf "%02d" $id)
  datadir=dataset${idstring}

  # check for required files ...
  if [ ! -d $datadir ]
      then
      echo " Directory $datadir does not exists, exiting ...."
      exit 1
  else

      #calcif_threshod=1600
      #inputname="initial_crop"
      inputname="initial_crop_FastNLmeans"
      calcif_threshod=1600

      # look for input image
      input_image=${datadir}/Images/${inputname}.vtk
      input_image1=${datadir}/Images/${inputname}_CalcOut.ami.gz
      
      input_filtered=${datadir}/Images/initial_crop_FastNLmeans.vtk

      if [ ! -e ${input_image1} ]
	  then
	  if [ -e ${input_image} ]
	      then
	      fill_calcif.amil ${input_image}   $calcif_threshod $input_filtered
	  else
	      echo "input image ${input_image} not found, skipping dataset ..."
	      continue
	  fi
      fi

      
      # look for the PDF image
      pdf_option1=${datadir}/cistib/image${idstring}-crop-den-PDF-01.vtk
      pdf_option2=${datadir}/cistib/image${idstring}-PDF-01.vtk

      if [ -e ${pdf_option1} ]
	  then
	  pdf_filename=${pdf_option1}
      else
	  if [ -e ${pdf_option2} ]
	      then
	      pdf_filename=${pdf_option2}
	  else
	      echo "Probability Density Function file not found, step to next dataset"
	      continue
	  fi
      fi
      
      
      # look/compute the centerline response
      center_filename="${input_image1}_response.ami.gz"

      maxrep_image=${datadir}/Images/${inputname}_CalcOut_MaxRep.ami.gz
      
#-o  $recompute_rep -eq "true" ))
      if [ $maxmethod=="multiline" ]
      then
        ~/projects/Fluid/fluid/Karl/scripts/Centerlines/RunMultiLines.amil ${input_image1} ${maxrep_image} 0.2 3.5 6 ${pdf_filename}
      else
        if  [ ! -e ${maxrep_image} ] 
        then
	        echo "maxrep.amil ${id} ${input_image1} ${pdf_filename} ${maxrep_image}"
	        maxrep.amil ${id} ${input_image1} ${pdf_filename} ${maxrep_image}
        fi
      fi

      
      echo "CTA_createpaths.amil $id  ${pdf_filename} ${maxrep_image}"
      CTA_createpaths.amil $id  ${pdf_filename} ${maxrep_image}
      
  fi    
done



