
members_blacklist=[
  'vtkPolyData::GetPointCells', # reference to pointer as parameter
  'vtkPolyData::GetCellPoints',  # idem
  'vtkSource::GetOutputs',       # double pointer
  'vtkProcessObject::GetInputs', # idem
  'vtkFixedPointVolumeRayCastMapper::LookupAndCombineIndependentColorsUC', # gives an error: to check
  'vtkFixedPointVolumeRayCastMapper::GetGradientNormal', # double pointer pb
  'vtkCellArray::GetNextCell', # reference to pointer
  'vtkCellArray::GetCell', # reference to pointer
  'vtkVolumeRayCastFunction::FunctionInitialize',
  'InternalTransformDerivative', # VTK: pointer to array ...
]
