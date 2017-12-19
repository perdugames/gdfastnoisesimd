<p align="center">
   <img src="https://raw.githubusercontent.com/PerduGames/gdfastnoisesimd/master/gdfastnoisesimd-logo.png"/>
</p>

# GDFastNoiseSIMD
gdfastnoisesimd is a module for the [FastNoiseSIMD](https://github.com/Auburns/FastNoiseSIMD/) lib. Thanks to [@Auburns](https://github.com/Auburns/).


## warning
If you are having problems compiling or getting errors while using the library in Godot, try commenting the line **#define FN_COMPILE_AVX2** in the file **FastNoiseSIMD.h** which is inside the **FastNoiseSIMD** directory in the **gdfastnoisesimd** module (Probably already be commented out by default).


## EXAMPLE
```gdscript
extends Node

var noise = GDFastNoiseSIMD.new()

func _ready():
  # Choose a seed to generate the noise. The results will be different for different seeds.
  noise.setSeed(16549)
  # Choose the type of noise.
  noise.setNoiseType(noise.SIMPLEX)
  # Always returns a one-dimensional float array.
  # If the size of the Z dimension is a multiple of 8 there is a slight performance boost.
  var arrayFloat = noise.getNoiseSet(0, 0, 0, 16, 16, 16)
  # All outputs are approximately bounded from -1.0 to 1.0, except for distance functions on cellular noise.
  print(arrayFloat)
  
  # 2D noise
  var otherArrayFloat = noise.getNoiseSet(0, 0, 0, 1, 16, 16)
  print(otherArrayFloat)
  
  # You can also call the specific noise function. 
  # Check out the DOC/API for all available functions.
  var arrayFloatPerlin = noise.getPerlinFractalSet(0, 0, 0, 16, 16, 16)
  print(arrayFloatPerlin)
  
```

## DOC

[Documentation](https://github.com/PerduGames/gdfastnoisesimd/wiki/DOC)

## API

#### ENUM_CONSTANT:
```gdscript

# NoiseTypes
  VALUE
  VALUE_FRACTAL
  PERLIN
  PERLIN_FRACTAL
  SIMPLEX
  SIMPLEX_FRACTAL
  WHITENOISE
  CELULAR
  CUBIC
  CUBIC_FRACTAL

# FractalTypes
  FBM
  BILLOW
  RIGIDMULTI

# CellularDistanceFunction
  EUCLIDEAN
  MANHATTAN
  NATURAL

# CellularReturnType
  CELLVALUE
  DISTANCE
  DISTANCE2
  DISTANCE2ADD
  DISTANCE2SUB
  DISTANCE2MUL
  DISTANCE2DIV
  NOISELOOKUP
  DISTANCE2CAVE

# PerturbType
  NONE
  GRADIENT
  GRADIENTFRACTAL
  NORMALISE
  GRADIENT_NORMALISE
  GRADIENTFRACTAL_NORMALISE

```
#### int getSIMDLevel(void)
#### void setSIMDLevel(int level)
#### int getSeed(void)
#### void setSeed(int seed)
#### void setFrequency(float frequency)
#### void setNoiseType(TypesNoise type)
#### void setAxisScales(float xScale, float yScale, float zScale)
#### PoolRealArray getNoiseSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getWhiteNoiseSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getValueSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getValueFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getPerlinSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getPerlinFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getSimplexSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getSimplexFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getCellularSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getCubicSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### PoolRealArray getCubicFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f)
#### void setFractalOctaves(int octaves)
#### void setFractalLacunarity(float lacunarity)
#### void setFractalGain(float gain)
#### void setFractalType(TypesFractal type)
#### void setCellularReturnType(ReturnTypeCellular type)
#### void setCellularDistanceFunction(DistanceFunctionCellular type)
#### void setCellularNoiseLookupType(TypesNoise type)
#### void setCellularNoiseLookupFrequency(float cellularNoiseLookupFrequency)
#### void setCellularDistance2Indicies(int cellularDistanceIndex0, int cellularDistanceIndex1)
#### void setCellularJitter(float cellularJitter)
#### void setPerturbType(TypePerturb type)
#### void setPerturbAmp(float perturbAmp)
#### void setPerturbFrequency(float perturbFrequency)
#### void setPerturbFractalOctaves(int perturbOctaves)
#### void setPerturbFractalLacunarity(float perturbLacunarity)
#### void setPerturbFractalGain(float perturbGain)
#### void setPerturbNormaliseLength(float perturbNormaliseLength)

## License
`gdfastnoisesimd` is under [MIT License](LICENSE).

## Author
[perdugames](https://github.com/PerduGames/)

## Note
If you need some function that is not in the module, create an issue stating that you need it.

