// MIT License
//
// Copyright (c) 2017 PerduGames
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

/* gdfastnoisesimd.cpp */

#include "gdfastnoisesimd.h"

GDFastNoiseSIMD::GDFastNoiseSIMD(){

    myNoise = FastNoiseSIMD::NewFastNoiseSIMD();

}

// -------------------ALL--------------------------------------------

int GDFastNoiseSIMD::getSIMDLevel(void){
    return myNoise->GetSIMDLevel();
}

void GDFastNoiseSIMD::setSIMDLevel(int level){
    myNoise->SetSIMDLevel(level);
}

int GDFastNoiseSIMD::getSeed(void){
	return myNoise->GetSeed();
}

void GDFastNoiseSIMD::setSeed(int seed){
    myNoise->SetSeed(seed);
}

void GDFastNoiseSIMD::setFrequency(float frequency){
    myNoise->SetFrequency(frequency);
}

void GDFastNoiseSIMD::setNoiseType(GDFastNoiseSIMD::TypesNoise type){
    FastNoiseSIMD::NoiseType noiseType = (FastNoiseSIMD::NoiseType)type;
    myNoise->SetNoiseType(noiseType);
}

void GDFastNoiseSIMD::setAxisScales(float xScale, float yScale, float zScale){
    myNoise->SetAxisScales(xScale, yScale, zScale);
}

PoolRealArray GDFastNoiseSIMD::getNoiseSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){

    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetNoiseSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getWhiteNoiseSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetWhiteNoiseSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getValueSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetValueSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getValueFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetValueFractalSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getPerlinSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetPerlinSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getPerlinFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetPerlinFractalSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getSimplexSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetSimplexSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getSimplexFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetSimplexFractalSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getCellularSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetCellularSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getCubicSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetCubicSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

PoolRealArray GDFastNoiseSIMD::getCubicFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier){
    PoolRealArray arrayFloat;
    arrayFloat.resize(xSize * ySize * zSize);

    float* noiseSet = myNoise->GetCubicFractalSet(xStart, yStart, zStart, xSize, ySize, zSize, scaleModifier);

    PoolRealArray::Write w = arrayFloat.write();
    memcpy(&w[0], noiseSet, sizeof(real_t) * (xSize * ySize * zSize));

    FastNoiseSIMD::FreeNoiseSet(noiseSet);
    return arrayFloat;

}

// -------------------FRACTAL--------------------------------------------

void GDFastNoiseSIMD::setFractalOctaves(int octaves){
    myNoise->SetFractalOctaves(octaves);
}

void GDFastNoiseSIMD::setFractalLacunarity(float lacunarity){
    myNoise->SetFractalLacunarity(lacunarity);
}

void GDFastNoiseSIMD::setFractalGain(float gain){
    myNoise->SetFractalGain(gain);
}

void GDFastNoiseSIMD::setFractalType(GDFastNoiseSIMD::TypesFractal type){
    FastNoiseSIMD::FractalType fractalType = (FastNoiseSIMD::FractalType)type;
    myNoise->SetFractalType(fractalType);
}

// -------------------CELLULAR--------------------------------------------

void GDFastNoiseSIMD::setCellularReturnType(GDFastNoiseSIMD::ReturnTypeCellular type){
    FastNoiseSIMD::CellularReturnType cellularReturnType = (FastNoiseSIMD::CellularReturnType)type;
    myNoise->SetCellularReturnType(cellularReturnType);
}

void GDFastNoiseSIMD::setCellularDistanceFunction(GDFastNoiseSIMD::DistanceFunctionCellular type){
    FastNoiseSIMD::CellularDistanceFunction cellularDistanceFunction = (FastNoiseSIMD::CellularDistanceFunction)type;
    myNoise->SetCellularDistanceFunction(cellularDistanceFunction);
}

void GDFastNoiseSIMD::setCellularNoiseLookupType(GDFastNoiseSIMD::TypesNoise type){
    FastNoiseSIMD::NoiseType cellularNoiseLookupType = (FastNoiseSIMD::NoiseType)type;
    myNoise->SetCellularNoiseLookupType(cellularNoiseLookupType);
}

void GDFastNoiseSIMD::setCellularNoiseLookupFrequency(float cellularNoiseLookupFrequency){
    myNoise->SetCellularNoiseLookupFrequency(cellularNoiseLookupFrequency);
}

void GDFastNoiseSIMD::setCellularDistance2Indicies(int cellularDistanceIndex0, int cellularDistanceIndex1){
    myNoise->SetCellularDistance2Indicies(cellularDistanceIndex0, cellularDistanceIndex1);
}

void GDFastNoiseSIMD::setCellularJitter(float cellularJitter){
    myNoise->SetCellularJitter(cellularJitter);
}

// -------------------PERTURB--------------------------------------------
void GDFastNoiseSIMD::setPerturbType(GDFastNoiseSIMD::TypePerturb type){
    FastNoiseSIMD::NoiseType perturbType = (FastNoiseSIMD::NoiseType)type;
    myNoise->SetCellularNoiseLookupType(perturbType);
}

void GDFastNoiseSIMD::setPerturbAmp(float perturbAmp){
    myNoise->SetPerturbAmp(perturbAmp);
}

void GDFastNoiseSIMD::setPerturbFrequency(float perturbFrequency){
    myNoise->SetPerturbFrequency(perturbFrequency);
}

void GDFastNoiseSIMD::setPerturbFractalOctaves(int perturbOctaves){
    myNoise->SetPerturbFractalOctaves(perturbOctaves);
}

void GDFastNoiseSIMD::setPerturbFractalLacunarity(float perturbLacunarity){
    myNoise->SetPerturbFractalLacunarity(perturbLacunarity);
}

void GDFastNoiseSIMD::setPerturbFractalGain(float perturbGain){
    myNoise->SetPerturbFractalGain(perturbGain);
}

void GDFastNoiseSIMD::setPerturbNormaliseLength(float perturbNormaliseLength){
    myNoise->SetPerturbNormaliseLength(perturbNormaliseLength);
}

void GDFastNoiseSIMD::_bind_methods() {
    BIND_ENUM_CONSTANT(VALUE);
    BIND_ENUM_CONSTANT(VALUE_FRACTAL);
    BIND_ENUM_CONSTANT(PERLIN);
    BIND_ENUM_CONSTANT(PERLIN_FRACTAL);
    BIND_ENUM_CONSTANT(SIMPLEX);
    BIND_ENUM_CONSTANT(SIMPLEX_FRACTAL);
    BIND_ENUM_CONSTANT(WHITENOISE);
    BIND_ENUM_CONSTANT(CELULAR);
    BIND_ENUM_CONSTANT(CUBIC);
    BIND_ENUM_CONSTANT(CUBIC_FRACTAL);

    BIND_ENUM_CONSTANT(FBM);
    BIND_ENUM_CONSTANT(BILLOW);
    BIND_ENUM_CONSTANT(RIGIDMULTI);

    BIND_ENUM_CONSTANT(EUCLIDEAN);
    BIND_ENUM_CONSTANT(MANHATTAN);
    BIND_ENUM_CONSTANT(NATURAL);

    BIND_ENUM_CONSTANT(CELLVALUE);
    BIND_ENUM_CONSTANT(DISTANCE);
    BIND_ENUM_CONSTANT(DISTANCE2);
    BIND_ENUM_CONSTANT(DISTANCE2ADD);
    BIND_ENUM_CONSTANT(DISTANCE2SUB);
    BIND_ENUM_CONSTANT(DISTANCE2MUL);
    BIND_ENUM_CONSTANT(DISTANCE2DIV);
    BIND_ENUM_CONSTANT(NOISELOOKUP);
    BIND_ENUM_CONSTANT(DISTANCE2CAVE);

    BIND_ENUM_CONSTANT(NONE);
    BIND_ENUM_CONSTANT(GRADIENT);
    BIND_ENUM_CONSTANT(GRADIENTFRACTAL);
    BIND_ENUM_CONSTANT(NORMALISE);
    BIND_ENUM_CONSTANT(GRADIENT_NORMALISE);
    BIND_ENUM_CONSTANT(GRADIENTFRACTAL_NORMALISE);

    ClassDB::bind_method(D_METHOD("getSIMDLevel"),&GDFastNoiseSIMD::getSIMDLevel);
    ClassDB::bind_method(D_METHOD("setSIMDLevel"),&GDFastNoiseSIMD::setSIMDLevel);
	ClassDB::bind_method(D_METHOD("getSeed"),&GDFastNoiseSIMD::getSeed);
	ClassDB::bind_method(D_METHOD("setSeed"),&GDFastNoiseSIMD::setSeed);
	ClassDB::bind_method(D_METHOD("setFrequency"),&GDFastNoiseSIMD::setFrequency);
	ClassDB::bind_method(D_METHOD("setNoiseType"),&GDFastNoiseSIMD::setNoiseType);
    ClassDB::bind_method(D_METHOD("setAxisScales"),&GDFastNoiseSIMD::setAxisScales);
    ClassDB::bind_method(D_METHOD("getNoiseSet"),&GDFastNoiseSIMD::getNoiseSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getWhiteNoiseSet"),&GDFastNoiseSIMD::getWhiteNoiseSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getValueSet"),&GDFastNoiseSIMD::getValueSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getValueFractalSet"),&GDFastNoiseSIMD::getValueFractalSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getPerlinSet"),&GDFastNoiseSIMD::getPerlinSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getPerlinFractalSet"),&GDFastNoiseSIMD::getPerlinFractalSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getSimplexSet"),&GDFastNoiseSIMD::getSimplexSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getSimplexFractalSet"),&GDFastNoiseSIMD::getSimplexFractalSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getCellularSet"),&GDFastNoiseSIMD::getCellularSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getCubicSet"),&GDFastNoiseSIMD::getCubicSet, DEFVAL(1.0));
    ClassDB::bind_method(D_METHOD("getCubicFractalSet"),&GDFastNoiseSIMD::getCubicFractalSet, DEFVAL(1.0));

    ClassDB::bind_method(D_METHOD("setFractalOctaves"),&GDFastNoiseSIMD::setFractalOctaves);
    ClassDB::bind_method(D_METHOD("setFractalLacunarity"),&GDFastNoiseSIMD::setFractalLacunarity);
    ClassDB::bind_method(D_METHOD("setFractalGain"),&GDFastNoiseSIMD::setFractalGain);
    ClassDB::bind_method(D_METHOD("setFractalType"),&GDFastNoiseSIMD::setFractalType);

    ClassDB::bind_method(D_METHOD("setCellularReturnType"),&GDFastNoiseSIMD::setCellularReturnType);
    ClassDB::bind_method(D_METHOD("setCellularDistanceFunction"),&GDFastNoiseSIMD::setCellularDistanceFunction);
    ClassDB::bind_method(D_METHOD("setCellularNoiseLookupType"),&GDFastNoiseSIMD::setCellularNoiseLookupType);
    ClassDB::bind_method(D_METHOD("setCellularNoiseLookupFrequency"),&GDFastNoiseSIMD::setCellularNoiseLookupFrequency);
    ClassDB::bind_method(D_METHOD("setCellularDistance2Indicies"),&GDFastNoiseSIMD::setCellularDistance2Indicies);
    ClassDB::bind_method(D_METHOD("setCellularJitter"),&GDFastNoiseSIMD::setCellularJitter);

    ClassDB::bind_method(D_METHOD("setPerturbType"),&GDFastNoiseSIMD::setPerturbType);
    ClassDB::bind_method(D_METHOD("setPerturbAmp"),&GDFastNoiseSIMD::setPerturbAmp);
    ClassDB::bind_method(D_METHOD("setPerturbFrequency"),&GDFastNoiseSIMD::setPerturbFrequency);
    ClassDB::bind_method(D_METHOD("setPerturbFractalOctaves"),&GDFastNoiseSIMD::setPerturbFractalOctaves);
    ClassDB::bind_method(D_METHOD("setPerturbFractalLacunarity"),&GDFastNoiseSIMD::setPerturbFractalLacunarity);
    ClassDB::bind_method(D_METHOD("setPerturbFractalGain"),&GDFastNoiseSIMD::setPerturbFractalGain);
    ClassDB::bind_method(D_METHOD("setPerturbNormaliseLength"),&GDFastNoiseSIMD::setPerturbNormaliseLength);

}
