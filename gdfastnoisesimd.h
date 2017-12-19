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

/* gdfastnoisesimd.h */

#ifndef GD_FAST_NOISE_SIMD
#define GD_FAST_NOISE_SIMD

#include "reference.h"
#include "FastNoiseSIMD.h"
#include "array.h"
#include "method_bind.h"
#include "method_bind_ext.gen.inc"

class GDFastNoiseSIMD : public Reference {

    GDCLASS(GDFastNoiseSIMD,Reference);

protected:
    static void _bind_methods();

public:

    GDFastNoiseSIMD();

    enum TypesNoise {
        VALUE,
        VALUE_FRACTAL,
        PERLIN,
        PERLIN_FRACTAL,
        SIMPLEX,
        SIMPLEX_FRACTAL,
        WHITENOISE,
        CELULAR,
        CUBIC,
        CUBIC_FRACTAL
    };

    enum TypesFractal {
        FBM,
        BILLOW,
        RIGIDMULTI
     };

    enum DistanceFunctionCellular {
        EUCLIDEAN,
        MANHATTAN,
        NATURAL
    };

	enum ReturnTypeCellular {
        CELLVALUE,
        DISTANCE,
        DISTANCE2,
        DISTANCE2ADD,
        DISTANCE2SUB,
        DISTANCE2MUL,
        DISTANCE2DIV,
        NOISELOOKUP,
        DISTANCE2CAVE
    };

    enum TypePerturb {
        NONE,
        GRADIENT,
        GRADIENTFRACTAL,
        NORMALISE,
        GRADIENT_NORMALISE,
        GRADIENTFRACTAL_NORMALISE
    };

// -------------------ALL--------------------------------------------
    // Returns highest detected level of CPU support
    // 5: ARM NEON
    // 4: AVX512
    // 3: AVX2 & FMA3
    // 2: SSE4.1
    // 1: SSE2
    // 0: Fallback, no SIMD support
    int getSIMDLevel(void);

    // Sets the SIMD level for newly created FastNoiseSIMD objects
    // 5: ARM NEON
    // 4: AVX512
    // 3: AVX2 & FMA3
    // 2: SSE4.1
    // 1: SSE2
    // 0: Fallback, no SIMD support
    // -1: Auto-detect fastest supported (Default)
    // Caution: Setting this manually can cause crashes on CPUs that do not support that level
    // Caution: Changing this after creating FastNoiseSIMD objects has undefined behaviour
    void setSIMDLevel(int level);

    // Returns seed used for all noise types
    int getSeed(void);

    // Sets seed used for all noise types
    // Default: 1337
    void setSeed(int seed);

    // Sets frequency for all noise types
	// Default: 0.01
    void setFrequency(float frequency);

    // Sets noise return type of (Get/Fill)NoiseSet()
	// Default: SimplexFractal
    // Possible noise types:
    // Value
    // ValueFractal
    // Perlin
    // PerlinFractal
    // Simplex
    // SimplexFractal
    // WhiteNoise
    // Cellular
    // Cubic
    // CubicFractal
    void setNoiseType(TypesNoise type);

    // Sets scaling factor for individual axis
	// Defaults: 1.0
	void setAxisScales(float xScale, float yScale, float zScale);

    PoolRealArray getNoiseSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);

    PoolRealArray getWhiteNoiseSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);

    PoolRealArray getValueSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);
	PoolRealArray getValueFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);

    PoolRealArray getPerlinSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);
	PoolRealArray getPerlinFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);

    PoolRealArray getSimplexSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);
	PoolRealArray getSimplexFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);

    PoolRealArray getCellularSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);

    PoolRealArray getCubicSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);
	PoolRealArray getCubicFractalSet(int xStart, int yStart, int zStart, int xSize, int ySize, int zSize, float scaleModifier=1.0f);


// -------------------FRACTAL--------------------------------------------
    // Sets octave count for all fractal noise types
	// Default: 3
	void setFractalOctaves(int octaves);

	// Sets octave lacunarity for all fractal noise types
	// Default: 2.0
	void setFractalLacunarity(float lacunarity);

	// Sets octave gain for all fractal noise types
	// Default: 0.5
	void setFractalGain(float gain);

	// Sets method for combining octaves in all fractal noise types
	// Default: FBM
	void setFractalType(TypesFractal type);

// -------------------CELLULAR--------------------------------------------
    // Sets return type from cellular noise calculations
	// Default: Distance
	void setCellularReturnType(ReturnTypeCellular type);

	// Sets distance function used in cellular noise calculations
	// Default: Euclidean
	void setCellularDistanceFunction(DistanceFunctionCellular type);

	// Sets the type of noise used if cellular return type is set the NoiseLookup
	// Default: Simplex
	void setCellularNoiseLookupType(TypesNoise type);

	// Sets relative frequency on the cellular noise lookup return type
	// Default: 0.2
	void setCellularNoiseLookupFrequency(float cellularNoiseLookupFrequency);

	// Sets the 2 distance indicies used for distance2 return types
	// Default: 0, 1
	// Note: index0 should be lower than index1
	// Both indicies must be >= 0, index1 must be < 4
	void setCellularDistance2Indicies(int cellularDistanceIndex0, int cellularDistanceIndex1);

	// Sets the maximum distance a cellular point can move from it's grid position
	// Setting this high will make artifacts more common
	// Default: 0.45
	void setCellularJitter(float cellularJitter);

// -------------------PERTURB--------------------------------------------]
    // Enables position perturbing for all noise types
    // Default: None
    void setPerturbType(TypePerturb type);

    // Sets the maximum distance the input position can be perturbed
    // Default: 1.0
    void setPerturbAmp(float perturbAmp);

    // Set the relative frequency for the perturb gradient
    // Default: 0.5
    void setPerturbFrequency(float perturbFrequency);

    // Sets octave count for perturb fractal types
    // Default: 3
    void setPerturbFractalOctaves(int perturbOctaves);

    // Sets octave lacunarity for perturb fractal types
    // Default: 2.0
    void setPerturbFractalLacunarity(float perturbLacunarity);

    // Sets octave gain for perturb fractal types
    // Default: 0.5
    void setPerturbFractalGain(float perturbGain);

    // Sets the length for vectors after perturb normalising
    // Default: 1.0
    void setPerturbNormaliseLength(float perturbNormaliseLength);

private:
    FastNoiseSIMD* myNoise;

};

VARIANT_ENUM_CAST(GDFastNoiseSIMD::TypesNoise);
VARIANT_ENUM_CAST(GDFastNoiseSIMD::TypesFractal);
VARIANT_ENUM_CAST(GDFastNoiseSIMD::DistanceFunctionCellular);
VARIANT_ENUM_CAST(GDFastNoiseSIMD::ReturnTypeCellular);
VARIANT_ENUM_CAST(GDFastNoiseSIMD::TypePerturb);


#endif
