function im=readami(filename)
%
% Reads an image in amilab format and returns the corresponding matrix
%

  fid=fopen(filename,'r');
  fscanf(fid,'AMIMAGE 1.1\n');
  fscanf(fid,'(\n');
    xdim = fscanf(fid,'XDim = %d\n',1);
    ydim = fscanf(fid,'YDim = %d\n',1);
    zdim = fscanf(fid,'ZDim = %d\n',1);
    vdim = fscanf(fid,'VDim = %d\n',1);
    vsx= fscanf(fid,'VoxSizeX = %f\n',1);
    vsy = fscanf(fid,'VoxSizeY = %f\n',1);
    vsz = fscanf(fid,'VoxSizeZ = %f\n',1);
    tr_x = fscanf(fid,'TranslX = %f\n',1);
    tr_y = fscanf(fid,'TranslY = %f\n',1);
    tr_z = fscanf(fid,'TranslZ = %f\n',1);
    repres = fscanf(fid,'Repres = %s\n',1);
    type   = fscanf(fid,'Type = %s\n',1);
    endian = fscanf(fid,'Endianness = %s\n',1)
    scanorder = fscanf(fid,'ScanOrder  = %s\n)\n',1)

  if strcmp(repres,'UCHAR')==1
    prec='uint8';
    precsize=1;
  elseif strcmp(repres,'FLOAT')==1
    prec='float';
    precsize=4;
  elseif strcmp(repres,'DOUBLE')==1
    prec='double';
    precsize=8;
  end
  
  if strcmp(endian,'LITTLE')==1
    mf = 'ieee-le';
  elseif strcmp(endian,'BIG')==1
    mf = 'ieee-be';
  end
  fseek(fid,-xdim*ydim*vdim*precsize,'eof')
  [im,count]=fread(fid,xdim*ydim*vdim,prec,0,mf);
  count
  xdim*ydim*vdim
  if vdim==1
    im = reshape(im,[xdim ydim vdim]);
    im=rot90(im,-1);
  else
    im = reshape(im,[vdim xdim ydim]);
  end
  fclose(fid);
