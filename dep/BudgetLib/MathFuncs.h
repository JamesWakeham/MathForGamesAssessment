#pragma once
#include <math.h>

namespace MathFuncs
{
	class Matrix2;
	class Vector2
	{
	public:
		Vector2();
		Vector2(const Vector2 &other);
		~Vector2();
		Vector2(const float _x, const float _y);
		Vector2(const float _x);
		float x, y;

		float Vector2::Dot(Vector2);
		float Vector2::Magnitude();
		Vector2 Vector2::Normalize();

		Vector2 operator+ (const Vector2);
		Vector2 operator- (const Vector2);
		Vector2 operator* (const float f);
		operator float* ();
		float values[2];
	};

	class Vector3
	{
	public:
		Vector3();
		Vector3(const Vector3 &other);
		~Vector3();		
		Vector3(const float _x, const float _y, const float _z);
		Vector3(const float _x, const float _y);
		Vector3(const float _x);
		float x, y, z;

		float Vector3::Dot(Vector3);
		Vector3 Vector3::Cross(Vector3);
		float Vector3::Magnitude();
		Vector3 Vector3::Normalize();

		Vector3 operator+ (const Vector3);
		Vector3 operator- (const Vector3);
		Vector3 operator* (const float f);
		operator float* ();
		float values[3];
	};

	class Vector4
	{
	public:
		Vector4();
		Vector4(const Vector4 &other);
		~Vector4();
		Vector4(const float _x, const float _y, const float _z, const float _w);
		Vector4(const float _x, const float _y, const float _z);
		Vector4(const float _x, const float _y);
		Vector4(const float _x);
		float x, y, z, w;

		float Vector4::Dot(Vector4);
		Vector4 Vector4::Cross(Vector4);
		float Vector4::Magnitude();
		Vector4 Vector4::Normalize();

		Vector4 operator+ (const Vector4);
		Vector4 operator- (const Vector4);
		Vector4 operator* (const float f);
		operator float* ();
		float values[4];
	};

	class Matrix2
	{
	public:
		Matrix2();
		Matrix2(const Matrix2 &other);
		~Matrix2();
		Matrix2(const float _x, const float _y, const float _z, const float _w);
		float value[2][2];
		Matrix2 SetRotateZ(float theta);
		Matrix2 operator* (const Matrix2);
		operator float* ();
	private:

	};

	class Matrix3
	{
	public:
		Matrix3();
		Matrix3(const Matrix3 &other);
		~Matrix3();
		Matrix3(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i);
		float value[3][3];
		Matrix3 SetRotateX(float theta);
		Matrix3 SetRotateY(float theta);
		Matrix3 SetRotateZ(float theta);
		Matrix3 operator* (const Matrix3);
		operator float* ();
	private:

	};

	class Matrix4
	{
	public:
		Matrix4();
		Matrix4(const Matrix4 &other);
		~Matrix4();
		Matrix4(const float a, const float b, const float c, const float d,
				const float e, const float f, const float g, const float h, 
				const float i, const float j, const float k, const float l, 
				const float m, const float n, const float o, const float p);
		float value[4][4];
		Matrix4 SetRotateX(float theta);
		Matrix4 SetRotateY(float theta);
		Matrix4 SetRotateZ(float theta);
		Matrix4 operator* (const Matrix4);
		operator float* ();
	private:
	};

#pragma region AgnosticFuncs
	Vector2 operator* (float, Vector2);
	Vector3 operator* (float, Vector3);
	Vector4 operator* (float, Vector4);
	Vector2 operator* (const Matrix2 lhs, const Vector2 rhs);
	float Mag(const Vector4);
	Vector4 Norm(const Vector4);
#pragma endregion
}
