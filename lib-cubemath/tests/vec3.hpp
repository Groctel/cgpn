#include <gtest/gtest.h>
#include "vecx/vec3.tpp"

TEST (Vec3, DefaultConstructor)
{
	Vec3c vecc;
	Vec3f vecd;
	Vec3f vecf;
	Vec3i veci;
	Vec3u vecu;
}

TEST (Vec3, AssigningMakesTwoVec3Equal)
{
	Vec3c vecc;
	Vec3f vecd;
	Vec3f vecf;
	Vec3i veci;
	Vec3u vecu;

	Vec3c vecc2 = vecc;
	Vec3f vecd2 = vecd;
	Vec3f vecf2 = vecf;
	Vec3i veci2 = veci;
	Vec3u vecu2 = vecu;

	EXPECT_EQ(vecc, vecc2);
	EXPECT_EQ(vecd, vecd2);
	EXPECT_EQ(vecf, vecf2);
	EXPECT_EQ(veci, veci2);
	EXPECT_EQ(vecu, vecu2);
}

TEST (Vec3, CopyingMakesTwoVec3Equal)
{
	Vec3c vecc;
	Vec3f vecd;
	Vec3f vecf;
	Vec3i veci;
	Vec3u vecu;

	Vec3c vecc2(vecc);
	Vec3f vecd2(vecd);
	Vec3f vecf2(vecf);
	Vec3i veci2(veci);
	Vec3u vecu2(vecu);

	EXPECT_EQ(vecc, vecc2);
	EXPECT_EQ(vecd, vecd2);
	EXPECT_EQ(vecf, vecf2);
	EXPECT_EQ(veci, veci2);
	EXPECT_EQ(vecu, vecu2);
}

TEST (Vec3, ConstructByFilling)
{
	uint_fast8_t c  = 31;
	double d        = 543534.543;
	float f         = 2423.4123;
	int_fast32_t i  = -23423432;
	uint_fast32_t u = 32142354;

	Vec3c vecc(c);
	Vec3d vecd(d);
	Vec3f vecf(f);
	Vec3i veci(i);
	Vec3u vecu(u);

	EXPECT_EQ(vecc, Vec3c({31, 31, 31}));
	EXPECT_EQ(vecd, Vec3d({543534.543, 543534.543, 543534.543}));
	EXPECT_EQ(vecf, Vec3f({2423.4123, 2423.4123, 2423.4123}));
	EXPECT_EQ(veci, Vec3i({-23423432, -23423432, -23423432}));
	EXPECT_EQ(vecu, Vec3u({32142354, 32142354, 32142354}));
}

TEST (Vec3, ConstructByInitList)
{
	uint_fast8_t c  = 31;
	double d        = 543534.543;
	float f         = 2423.4123;
	int_fast32_t i  = -23423432;
	uint_fast32_t u = 32142354;

	Vec3c vecc({c, c, c});
	Vec3d vecd({d, d, d});
	Vec3f vecf({f, f, f});
	Vec3i veci({i, i, i});
	Vec3u vecu({u, u, u});

	vecc = {c, c, c};
	vecd = {d, d, d};
	vecf = {f, f, f};
	veci = {i, i, i};
	vecu = {u, u, u};
}

TEST (Vec3, AccessingElements)
{
	Vec3c vecc({5, 9, 18});

	EXPECT_EQ(vecc[0], 5);
	EXPECT_EQ(vecc[1], 9);
	EXPECT_EQ(vecc[2], 18);
}

TEST (Vec3, EqualityAndInequality)
{
	Vec3c vecc1({5, 9, 18});
	Vec3c vecc2({8, 6,  9});

	EXPECT_EQ(vecc1, vecc1);
	EXPECT_EQ(vecc2, vecc2);
	EXPECT_NE(vecc1, vecc2);
}

TEST (Vec3, Addition_NoSideEffects)
{
	Vec3i veci1({7, 8, 3});
	Vec3i veci2({1, 3, 4});
	Vec3i veci3 = veci1 + veci2;

	EXPECT_EQ(veci1, Vec3i({7, 8,  3}));
	EXPECT_EQ(veci2, Vec3i({1, 3,  4}));
	EXPECT_EQ(veci3, Vec3i({8, 11, 7}));
}

TEST (Vec3, AdditionAssignment)
{
	Vec3i veci1({7, 8, 3});
	Vec3i veci2({1, 3, 4});
	veci1 += veci2;

	EXPECT_EQ(veci1, Vec3i({8, 11, 7}));
	EXPECT_EQ(veci2, Vec3i({1, 3,  4}));
}

TEST (Vec3, Subtraction_NoSideEffects)
{
	Vec3i veci1({7, 8, 3});
	Vec3i veci2({1, 3, 4});
	Vec3i veci3 = veci1 - veci2;

	EXPECT_EQ(veci1, Vec3i({7, 8,  3}));
	EXPECT_EQ(veci2, Vec3i({1, 3,  4}));
	EXPECT_EQ(veci3, Vec3i({6, 5, -1}));
}

TEST (Vec3, SubtractionAssignment)
{
	Vec3i veci1({7, 8, 3});
	Vec3i veci2({1, 3, 4});
	veci1 -= veci2;

	EXPECT_EQ(veci1, Vec3i({6, 5, -1}));
	EXPECT_EQ(veci2, Vec3i({1, 3,  4}));
}

TEST (Vec3, ScalarProduct_NoSideEffects)
{
	Vec3i veci1({7, 8, 3});
	Vec3i veci2 = veci1 * 2;

	EXPECT_EQ(veci1[0], 7);
	EXPECT_EQ(veci1[1], 8);
	EXPECT_EQ(veci1[2], 3);

	EXPECT_EQ(veci2[0], 14);
	EXPECT_EQ(veci2[1], 16);
	EXPECT_EQ(veci2[2], 6);

	EXPECT_EQ(veci1, Vec3i({ 7,  8, 3}));
	EXPECT_EQ(veci2, Vec3i({14, 16, 6}));
}

TEST (Vec3, ScalarProductAssignment)
{
	Vec3i veci1({7, 8, 3});
	veci1 *= 2;

	EXPECT_EQ(veci1, Vec3i({14, 16, 6}));
}

TEST (Vec3, VectorCrossProduct_NoSideEffects)
{
	Vec3i veci1({7, 8, 3});
	Vec3i veci2({1, 3, 4});
	Vec3i veci3 = veci1 * veci2;

	EXPECT_EQ(veci1, Vec3i({ 7,   8,  3}));
	EXPECT_EQ(veci2, Vec3i({ 1,   3,  4}));
	EXPECT_EQ(veci3, Vec3i({23, -25, 13}));
}

TEST (Vec3, VectorCrossProductAssignment)
{
	Vec3i veci1({7, 8, 3});
	Vec3i veci2({1, 3, 4});
	veci1 *= veci2;

	EXPECT_EQ(veci1, Vec3i({23, -25, 13}));
	EXPECT_EQ(veci2, Vec3i({ 1,   3,  4}));
}

TEST (Vec3, ScalarDivision_NoSideEffects)
{
	Vec3i veci1({7, 8, 3});
	Vec3i veci2 = veci1 / 2;

	EXPECT_EQ(veci1, Vec3i({7, 8, 3}));
	EXPECT_EQ(veci2, Vec3i({3, 4, 1}));
}

TEST (Vec3, ScalarDivisionAssignment)
{
	Vec3i veci1({7, 8, 3});
	veci1 /= 2;

	EXPECT_EQ(veci1, Vec3i({3, 4, 1}));
}

TEST (Vec3, DotProduct_NoSideEffects)
{
	Vec3i veci1({7, 8, 3});
	Vec3i veci2({1, 3, 4});

	int_fast32_t dot = veci1 | veci2;

	EXPECT_EQ(veci1, Vec3i({7, 8, 3}));
	EXPECT_EQ(veci2, Vec3i({1, 3, 4}));
	EXPECT_EQ(dot, 43);
}

TEST (Vec3, Normalise)
{
	Vec3f vecf({7, 8, 3});
	vecf.Normalise();

	ASSERT_EQ(vecf, Vec3f({0.6337502, 0.7242859, 0.2716072}));
}
