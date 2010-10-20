#!/bin/bash

if [ $# -lt 3 ]
then
  echo "needs 3 arguments: first dataset number, last, and method (multiline or maxrep)"
fi

minid=$1
maxid=$2
method=$3

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

      if [ ! -d ${datadir}/cistib ]
      then
        mkdir ${datadir}/cistib
        mv  ${datadir}/image${idstring}-crop-den-PDF-01.vtk ${datadir}/cistib
      fi
      # look for the PDF image
      pdf_option1=${datadir}/cistib/image${idstring}-crop-den-PDF-01.vtk
      pdf_option2=${datadir}/cistib/image${idstring}-PDF-01.vtk
#      pdf_option3=${datadir}/image${idstring}-FastNLmeans-PDF-01.vtk
      pdf_option3=${datadir}/image${idstring}-FastNLmeans-PDF-01_half.ami.gz

      if [ -e ${pdf_option1} ]
      then
        pdf_filename=${pdf_option1}
      else
        if [ -e ${pdf_option2} ]
        then
          pdf_filename=${pdf_option2}
        else
          if [ -e ${pdf_option3} ]
          then
            pdf_filename=${pdf_option3}
          else
            echo "Probability Density Function file not found, step to next dataset"
            continue
          fi
        fi
      fi

      echo "pdf_filename = ${pdf_filename}"
     #calcif_threshod=1600
      #inputname="initial_crop"
      #inputname="initial_crop_FastNLmeans"

      # look for input image
      #input_image=${datadir}/Images/${inputname}.vtk

      
      # look/compute the centerline response

      if [ "$method" = "multiline" ]
      then
        maxrep_image="${pdf_filename}_response.ami.gz"

        if [ ! -f ${maxrep_image} ]
        then 
          echo "~/projects/Fluid/fluid/Karl/scripts/Centerlines/RunMultiLines.amil ${pdf_filename} ${maxrep_image} 0.2 3.5 6 ${pdf_filename}"
          ~/projects/Fluid/fluid/Karl/scripts/Centerlines/RunMultiLines.amil ${pdf_filename} ${maxrep_image} 0.2 3.5 6 ${pdf_filename}
        else
          echo "-------------  file ${maxrep_image} exists !!!"
        fi
      fi

      if [ "$method" = "maxrep" ]
      then
        maxrep_image="${pdf_filename}_maxrep.ami.gz"

        if [ ! -f ${maxrep_image} ]
        then 
          echo "maxrep.amil ${id} ${input_image1} ${pdf_filename} ${maxrep_image}"
          maxrep.amil ${id} ${pdf_filename} ${pdf_filename} ${maxrep_image}
        else
          echo "-------------  file ${maxrep_image} exists !!!"
        fi
      fi

      echo "CTA_createpaths.amil $id  ${pdf_filename} ${maxrep_image}"
      CTA_createpaths.amil $id  ${pdf_filename} ${maxrep_image}

  fi    
done



