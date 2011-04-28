function writeami(im,filename)
% Write a matrix in amilab image format

  fid=fopen(filename,'w+');
  imtype = class(im);
  im=rot90(im);
  dims=size(im);
  sdims = size(dims);
  if (sdims(2)>=1)
    ydim = dims(1);
  else
    ydim = 1;
  end
  if (sdims(2)>=2)
    xdim = dims(2);
  else
    xdim = 1;
  end
  if (sdims(2)>=3)
    vdim = dims(3);
  else 
    vdim = 1;
  end
  
  fprintf(fid,'AMIMAGE 1.1\n');
  fprintf(fid,'(\n');
  fprintf(fid,'XDim = %d\n',xdim);
  fprintf(fid,'YDim = %d\n',ydim);
  fprintf(fid,'ZDim = %d\n',1);
  fprintf(fid,'VDim = %d\n',vdim);
  if strcmp(imtype,'single')==1
    fprintf(fid,'Repres = %s\n','FLOAT');
  elseif strcmp(imtype,'double')==1
    fprintf(fid,'Repres = %s\n','DOUBLE');
  elseif strcmp(imtype,'uint8')==1
    fprintf(fid,'Repres = %s\n','UCHAR');
  end

  if (vdim==1)
    fprintf(fid,'Type = SCALAR\n');
  else
    if strcmp(imtype,'uint8')==1
      fprintf(fid,'Type = RGB\n');
    else
      fprintf(fid,'Type = VECTOR\n');
    end
  end
  fprintf(fid,'Endianness = LITTLE\n')
  fprintf(fid,')\n')
  cnt=fwrite(fid,im,class(im));
  fclose(fid);
