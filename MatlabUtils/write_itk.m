function write_itk(im,filename)
% Write a matrix in amilab image format

  fid=fopen(filename,'w+');
  imtype = class(im);
  dims=size(im);
  sdims = size(dims)
  if (sdims(1)>=1)
    xdim = dims(1)
  else
    xdim = 1;
  end
  if (sdims(2)>=1)
    ydim = dims(2)
  else
    ydim = 1;
  end
  %if (sdims(3)>=1)
  %  vdim = dims(3);
  %else 
    vdim = 1;
  %end
  
  fprintf(fid,'NDims = 2\n');
  fprintf(fid,'DimSize = %d %d\n',xdim,ydim);
  if strcmp(imtype,'single')==1
    fprintf(fid,'ElementType = %s\n','MET_FLOAT');
  elseif strcmp(imtype,'double')==1
    fprintf(fid,'ElementType = %s\n','MET_DOUBLE');
  elseif strcmp(imtype,'uint8')==1
    fprintf(fid,'ElementType = %s\n','MET_UCHAR');
  end

  fprintf(fid,'ElementSpacing = 1.0 1.0 1.0\n');
  fprintf(fid,'ElementByteOrderMSB = False\n')
  cnt=fwrite(fid,im,class(im));
  fclose(fid);
