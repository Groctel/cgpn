#include <gtest/gtest.h>
#include "vecx/vec3.tpp"

class Vec3Test : public ::testing::Test
{
protected:
	uint_fast8_t c  = 31;
	double d        = 543534.543;
	float f         = 2423.4123;
	int_fast32_t i  = -23423432;
	uint_fast32_t u = 32142354;

	Vec3c vecc;
	Vec3d vecd;
	Vec3f vecf;
	Vec3i veci;
	Vec3u vecu;

	Vec3c vecc1 = {5, 9, 18};
	Vec3c vecc2 = {8, 6, 9};

	Vec3d vecd1 = {3.5249,    5432.3897, 172.8301};
	Vec3d vecd2 = {5743.2805, 50.2137,   254.6862};

	Vec3f vecf1 = {32.1432f,  768.1343f, 9789.1345f};
	Vec3f vecf2 = {643.5348f, 75.4232f,  20.4701f};

	Vec3i veci1 = {7, 8, 3};
	Vec3i veci2 = {1, 3, 4};

	Vec3u vecu1 = {9, 5, 1};
	Vec3u vecu2 = {4, 2, 6};
};

TEST_F (Vec3Test, TuplesStartAsThreeZeroes)
{
	EXPECT_TRUE(vecc == Vec3c(0, 0, 0));
	EXPECT_TRUE(vecd.EpsilonEq(Vec3d(0, 0, 0)));
	EXPECT_TRUE(vecf.EpsilonEq(Vec3f(0, 0, 0)));
	EXPECT_TRUE(veci == Vec3i(0, 0, 0));
	EXPECT_TRUE(vecu == Vec3u(0, 0, 0));
}

TEST_F (Vec3Test, TuplesEqualThemselves)
{
	EXPECT_TRUE(vecc == vecc);
	EXPECT_TRUE(vecd.EpsilonEq(vecd));
	EXPECT_TRUE(vecf.EpsilonEq(vecf));
	EXPECT_TRUE(veci == veci);
	EXPECT_TRUE(vecu == vecu);

	EXPECT_EQ(vecc[0], vecc[0]);
	EXPECT_EQ(vecc[1], vecc[1]);
	EXPECT_EQ(vecc[2], vecc[2]);

	EXPECT_DOUBLE_EQ(vecd[0], vecd[0]);
	EXPECT_DOUBLE_EQ(vecd[1], vecd[1]);
	EXPECT_DOUBLE_EQ(vecd[2], vecd[2]);

	EXPECT_FLOAT_EQ(vecf[0], vecf[0]);
	EXPECT_FLOAT_EQ(vecf[1], vecf[1]);
	EXPECT_FLOAT_EQ(vecf[2], vecf[2]);

	EXPECT_EQ(veci[0], veci[0]);
	EXPECT_EQ(veci[1], veci[1]);
	EXPECT_EQ(veci[2], veci[2]);

	EXPECT_EQ(vecu[0], vecu[0]);
	EXPECT_EQ(vecu[1], vecu[1]);
	EXPECT_EQ(vecu[2], vecu[2]);
}

TEST_F (Vec3Test, AssigningMakesTwoVec3Equal)
{
	Vec3c vecc2 = vecc;
	Vec3d vecd2 = vecd;
	Vec3f vecf2 = vecf;
	Vec3i veci2 = veci;
	Vec3u vecu2 = vecu;

	EXPECT_TRUE(vecc == vecc2);
	EXPECT_TRUE(vecd.EpsilonEq(vecd2));
	EXPECT_TRUE(vecf.EpsilonEq(vecf2));
	EXPECT_TRUE(veci == veci2);
	EXPECT_TRUE(vecu == vecu2);
}

TEST_F (Vec3Test, CopyingMakesTwoVec3Equal)
{
	Vec3c vecc2(vecc);
	Vec3d vecd2(vecd);
	Vec3f vecf2(vecf);
	Vec3i veci2(veci);
	Vec3u vecu2(vecu);

	EXPECT_TRUE(vecc == vecc2);
	EXPECT_TRUE(vecd.EpsilonEq(vecd2));
	EXPECT_TRUE(vecf.EpsilonEq(vecf2));
	EXPECT_TRUE(veci == veci2);
	EXPECT_TRUE(vecu == vecu2);
}

TEST_F (Vec3Test, ConstructByFilling)
{
	Vec3c vecc(c);
	Vec3d vecd(d);
	Vec3f vecf(f);
	Vec3i veci(i);
	Vec3u vecu(u);

	EXPECT_TRUE(vecc == Vec3c(c, c, c));
	EXPECT_TRUE(vecd.EpsilonEq(Vec3d(d, d, d)));
	EXPECT_TRUE(vecf.EpsilonEq(Vec3f(f, f, f)));
	EXPECT_TRUE(veci == Vec3i(i, i, i));
	EXPECT_TRUE(vecu == Vec3u(u, u, u));
}

TEST_F (Vec3Test, EqualityAndInequality)
{
	EXPECT_TRUE(vecc1  == vecc1);
	EXPECT_TRUE(vecc2  == vecc2);
	EXPECT_FALSE(vecc1 == vecc2);

	EXPECT_TRUE(vecd1.EpsilonEq(vecd1));
	EXPECT_TRUE(vecd2.EpsilonEq(vecd2));
	EXPECT_FALSE(vecd1.EpsilonEq(vecd2));

	EXPECT_TRUE(vecf1.EpsilonEq(vecf1));
	EXPECT_TRUE(vecf2.EpsilonEq(vecf2));
	EXPECT_FALSE(vecf1.EpsilonEq(vecf2));

	EXPECT_TRUE(veci1  == veci1);
	EXPECT_TRUE(veci2  == veci2);
	EXPECT_FALSE(veci1 == veci2);

	EXPECT_TRUE(vecu1  == vecu1);
	EXPECT_TRUE(vecu2  == vecu2);
	EXPECT_FALSE(vecu1 == vecu2);
}

TEST_F (Vec3Test, Addition_NoSideEffects)
{
	Vec3c vecc3 = vecc1 + vecc2;

	EXPECT_TRUE(vecc1 == Vec3c(5,   9,   18));
	EXPECT_TRUE(vecc2 == Vec3c(8,   6,   9));
	EXPECT_TRUE(vecc3 == Vec3c(5+8, 9+6, 18+9));

	Vec3d vecd3 = vecd1 + vecd2;

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249,           5432.3897,         172.8301)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(5743.2805,        50.2137,           254.6862)));
	EXPECT_TRUE(vecd3.EpsilonEq(Vec3d(3.5249+5743.2805, 5432.3897+50.2137, 172.8301+254.6862)));

	Vec3f vecf3 = vecf1 + vecf2;

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f,           768.1343f,          9789.1345f)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(643.5348f,          75.4232f,           20.4701f)));
	EXPECT_TRUE(vecf3.EpsilonEq(Vec3f(32.1432f+643.5348f, 768.1343f+75.4232f, 9789.1345f+20.4701f)));

	Vec3i veci3 = veci1 + veci2;

	EXPECT_TRUE(veci1 == Vec3i(7,   8,   3));
	EXPECT_TRUE(veci2 == Vec3i(1,   3,   4));
	EXPECT_TRUE(veci3 == Vec3i(7+1, 8+3, 3+4));

	Vec3u vecu3 = vecu1 + vecu2;

	EXPECT_TRUE(vecu1 == Vec3u(9,   5,   1));
	EXPECT_TRUE(vecu2 == Vec3u(4,   2,   6));
	EXPECT_TRUE(vecu3 == Vec3u(9+4, 5+2, 1+6));
}

TEST_F (Vec3Test, AdditionAssignment)
{
	vecc1 += vecc2;

	EXPECT_TRUE(vecc1 == Vec3c(5+8, 9+6, 18+9));
	EXPECT_TRUE(vecc2 == Vec3c(8,   6,   9));

	vecd1 += vecd2;

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249+5743.2805, 5432.3897+50.2137, 172.8301+254.6862)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(5743.2805,        50.2137,           254.6862)));

	vecf1 += vecf2;

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f+643.5348f, 768.1343f+75.4232f, 9789.1345f+20.4701f)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(643.5348f,          75.4232f,           20.4701f)));

	veci1 += veci2;

	EXPECT_TRUE(veci1 == Vec3i(7+1, 8+3, 3+4));
	EXPECT_TRUE(veci2 == Vec3i(1,   3,   4));

	vecu1 += vecu2;

	EXPECT_TRUE(vecu1 == Vec3u(9+4, 5+2, 1+6));
	EXPECT_TRUE(vecu2 == Vec3u(4,   2,   6));
}

TEST_F (Vec3Test, Subtraction_NoSideEffects)
{
	Vec3c vecc3 = vecc1 - vecc2;

	EXPECT_TRUE(vecc1 == Vec3c(5,   9,   18));
	EXPECT_TRUE(vecc2 == Vec3c(8,   6,   9));
	EXPECT_TRUE(vecc3 == Vec3c(5-8, 9-6, 18-9));

	Vec3d vecd3 = vecd1 - vecd2;

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249,           5432.3897,         172.8301)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(5743.2805,        50.2137,           254.6862)));
	EXPECT_TRUE(vecd3.EpsilonEq(Vec3d(3.5249-5743.2805, 5432.3897-50.2137, 172.8301-254.6862)));

	Vec3f vecf3 = vecf1 - vecf2;

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f,           768.1343f,          9789.1345f)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(643.5348f,          75.4232f,           20.4701f)));
	EXPECT_TRUE(vecf3.EpsilonEq(Vec3f(32.1432f-643.5348f, 768.1343f-75.4232f, 9789.1345f-20.4701f)));

	Vec3i veci3 = veci1 - veci2;

	EXPECT_TRUE(veci1 == Vec3i(7,   8,   3));
	EXPECT_TRUE(veci2 == Vec3i(1,   3,   4));
	EXPECT_TRUE(veci3 == Vec3i(7-1, 8-3, 3-4));

	Vec3u vecu3 = vecu1 - vecu2;

	EXPECT_TRUE(vecu1 == Vec3u(9,   5,   1));
	EXPECT_TRUE(vecu2 == Vec3u(4,   2,   6));
	EXPECT_TRUE(vecu3 == Vec3u(9-4, 5-2, 1-6));
}

TEST_F (Vec3Test, SubtractionAssignment)
{
	vecc1 -= vecc2;

	EXPECT_TRUE(vecc1 == Vec3c(5-8, 9-6, 18-9));
	EXPECT_TRUE(vecc2 == Vec3c(8,   6,   9));

	vecd1 -= vecd2;

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249-5743.2805, 5432.3897-50.2137, 172.8301-254.6862)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(5743.2805,        50.2137,           254.6862)));

	vecf1 -= vecf2;

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f-643.5348f, 768.1343f-75.4232f, 9789.1345f-20.4701f)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(643.5348f,          75.4232f,           20.4701f)));

	veci1 -= veci2;

	EXPECT_TRUE(veci1 == Vec3i(7-1, 8-3, 3-4));
	EXPECT_TRUE(veci2 == Vec3i(1,   3,   4));

	vecu1 -= vecu2;

	EXPECT_TRUE(vecu1 == Vec3u(9-4, 5-2, 1-6));
	EXPECT_TRUE(vecu2 == Vec3u(4,   2,   6));
}

TEST_F (Vec3Test, ScalarProduct_NoSideEffects)
{
	vecc2 = vecc1 * 2;

	EXPECT_TRUE(vecc1 == Vec3c(5,   9,   18));
	EXPECT_TRUE(vecc2 == Vec3c(5*2, 9*2, 18*2));

	vecd2 = vecd1 * 2;

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249,   5432.3897,   172.8301)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(3.5249*2, 5432.3897*2, 172.8301*2)));

	vecf2 = vecf1 * 2;

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f,      768.1343f,      9789.1345f)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(32.1432f*2.0f, 768.1343f*2.0f, 9789.1345f*2.0f)));

	veci2 = veci1 * 2;

	EXPECT_TRUE(veci1 == Vec3i(7,   8,   3));
	EXPECT_TRUE(veci2 == Vec3i(7*2, 8*2, 3*2));

	vecu2 = vecu1 * 2;

	EXPECT_TRUE(vecu1 == Vec3u(9,   5,   1));
	EXPECT_TRUE(vecu2 == Vec3u(9*2, 5*2, 1*2));
}

TEST_F (Vec3Test, ScalarProductAssignment)
{
	vecc1 *= 2;
	EXPECT_TRUE(vecc1 == Vec3c(5*2, 9*2, 18*2));

	vecd1 *= 2;
	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249*2, 5432.3897*2, 172.8301*2)));

	vecf1 *= 2;
	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f*2.0f, 768.1343f*2.0f, 9789.1345f*2.0f)));

	veci1 *= 2;
	EXPECT_TRUE(veci1 == Vec3i(7*2, 8*2, 3*2));

	vecu1 *= 2;
	EXPECT_TRUE(vecu1 == Vec3u(9*2, 5*2, 1*2));
}

TEST_F (Vec3Test, VectorCrossProduct_NoSideEffects)
{
	Vec3c vecc3 = vecc1 * vecc2;

	EXPECT_TRUE(vecc1 == Vec3c(5,   9,  18));
	EXPECT_TRUE(vecc2 == Vec3c(8,   6,  9));
	EXPECT_TRUE(vecc3 == Vec3c(-27, 99, -42));

	Vec3d vecd3 = vecd1 * vecd2;

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249,    5432.3897, 172.8301)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(5743.2805, 50.2137,   254.6862)));

	EXPECT_TRUE(vecd3.EpsilonEq(Vec3d(
		5432.3897 * 254.6862  - 172.8301  * 50.2137,
		172.8301  * 5743.2805 - 3.5249    * 254.6862,
		3.5249    * 50.2137   - 5432.3897 * 5743.2805
	)));

	Vec3f vecf3 = vecf1 * vecf2;

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f,  768.1343f, 9789.1345f)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(643.5348f, 75.4232f,  20.4701f)));

	EXPECT_TRUE(vecf3.EpsilonEq(Vec3f(
		768.1343f  * 20.4701f  - 9789.1345f * 75.4232f,
		9789.1345f * 643.5348f - 32.1432f   * 20.4701f,
		32.1432f   * 75.4232f  - 768.1343f  * 643.5348f
	)));

	Vec3i veci3 = veci1 * veci2;

	EXPECT_TRUE(veci1 == Vec3i(7,   8,  3));
	EXPECT_TRUE(veci2 == Vec3i(1,   3,  4));
	EXPECT_TRUE(veci3 == Vec3i(23, -25, 13));

	Vec3u vecu3 = vecu1 * vecu2;

	EXPECT_TRUE(vecu1 == Vec3u(9,  5,   1));
	EXPECT_TRUE(vecu2 == Vec3u(4,  2,   6));
	EXPECT_TRUE(vecu3 == Vec3u(28, -50, -2));
}

TEST_F (Vec3Test, VectorCrossProductAssignment)
{
	vecc1 *= vecc2;

	EXPECT_TRUE(vecc1 == Vec3c(-27, 99, -42));
	EXPECT_TRUE(vecc2 == Vec3c(8,   6,  9));

	vecd1 *= vecd2;

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(
		5432.3897 * 254.6862  - 172.8301  * 50.2137,
		172.8301  * 5743.2805 - 3.5249    * 254.6862,
		3.5249    * 50.2137   - 5432.3897 * 5743.2805
	)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(5743.2805, 50.2137,   254.6862)));

	vecf1 *= vecf2;

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(
		768.1343f  * 20.4701f  - 9789.1345f * 75.4232f,
		9789.1345f * 643.5348f - 32.1432f   * 20.4701f,
		32.1432f   * 75.4232f  - 768.1343f  * 643.5348f
	)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(643.5348f, 75.4232f,  20.4701f)));

	veci1 *= veci2;

	EXPECT_TRUE(veci1 == Vec3i(23, -25, 13));
	EXPECT_TRUE(veci2 == Vec3i(1,   3,  4));

	vecu1 *= vecu2;

	EXPECT_TRUE(vecu1 == Vec3u(28, -50, -2));
	EXPECT_TRUE(vecu2 == Vec3u(4,  2,   6));
}

TEST_F (Vec3Test, ScalarDivision_NoSideEffects)
{
	vecc2 = vecc1 / 2;

	EXPECT_TRUE(vecc1 == Vec3c(5,   9,   18));
	EXPECT_TRUE(vecc2 == Vec3c(5/2, 9/2, 18/2));

	vecd2 = vecd1 / 2;

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249,   5432.3897,   172.8301)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(3.5249/2, 5432.3897/2, 172.8301/2)));

	vecf2 = vecf1 / 2;

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f,      768.1343f,      9789.1345f)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(32.1432f/2.0f, 768.1343f/2.0f, 9789.1345f/2.0f)));

	veci2 = veci1 / 2;

	EXPECT_TRUE(veci1 == Vec3i(7,   8,   3));
	EXPECT_TRUE(veci2 == Vec3i(7/2, 8/2, 3/2));

	vecu2 = vecu1 / 2;

	EXPECT_TRUE(vecu1 == Vec3u(9,   5,   1));
	EXPECT_TRUE(vecu2 == Vec3u(9/2, 5/2, 1/2));
}

TEST_F (Vec3Test, ScalarDivisionAssignment)
{
	vecc1 /= 2;
	EXPECT_TRUE(vecc1 == Vec3c(5/2, 9/2, 18/2));

	vecd1 /= 2;
	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249/2, 5432.3897/2, 172.8301/2)));

	vecf1 /= 2;
	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f/2.0f, 768.1343f/2.0f, 9789.1345f/2.0f)));

	veci1 /= 2;
	EXPECT_TRUE(veci1 == Vec3i(7/2, 8/2, 3/2));

	vecu1 /= 2;
	EXPECT_TRUE(vecu1 == Vec3u(9/2, 5/2, 1/2));
}

TEST_F (Vec3Test, DotProduct_NoSideEffects)
{
	uint_fast8_t dotc = vecc1 | vecc2;

	EXPECT_TRUE(vecc1 == Vec3c(5, 9, 18));
	EXPECT_TRUE(vecc2 == Vec3c(8, 6, 9));

	EXPECT_EQ(dotc, (uint_fast8_t) (5*8 + 9*6 + 18*9));

	double dotd = vecd1 | vecd2;

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(3.5249,    5432.3897, 172.8301)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(5743.2805, 50.2137,   254.6862)));

	EXPECT_EQ(dotd, 3.5249*5743.2805 + 5432.3897*50.2137 + 172.8301*254.6862);

	float dotf = vecf1 | vecf2;

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(32.1432f,  768.1343f, 9789.1345f)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(643.5348f, 75.4232f,  20.4701f)));

	EXPECT_EQ(dotf, 32.1432f*643.5348f + 768.1343f*75.4232f + 9789.1345f*20.4701f);

	int_fast32_t doti = veci1 | veci2;

	EXPECT_TRUE(veci1 == Vec3i(7, 8, 3));
	EXPECT_TRUE(veci2 == Vec3i(1, 3, 4));

	EXPECT_EQ(doti, 7*1 + 8*3 + 3*4);

	uint_fast32_t dotu = vecu1 | vecu2;

	EXPECT_TRUE(vecu1 == Vec3u(9, 5, 1));
	EXPECT_TRUE(vecu2 == Vec3u(4, 2, 6));

	EXPECT_EQ(dotu, 9*4 + 5*2 + 1*6);
}

TEST_F (Vec3Test, Normalise)
{
	vecd1.Normalise();
	vecd2.Normalise();

	EXPECT_TRUE(vecd1.EpsilonEq(Vec3d(0.0006485390212178315, 0.9994940846298701,   0.03179865071093646)));
	EXPECT_TRUE(vecd2.EpsilonEq(Vec3d(0.9989800992903894,    0.008734117550368266, 0.04429984664059017)));

	vecf1.Normalise();
	vecf2.Normalise();

	EXPECT_TRUE(vecf1.EpsilonEq(Vec3f(0.003273479f, 0.078227168f, 0.996930185f)));
	EXPECT_TRUE(vecf2.EpsilonEq(Vec3f(0.992706584f, 0.116346633f, 0.031576851f)));
}
