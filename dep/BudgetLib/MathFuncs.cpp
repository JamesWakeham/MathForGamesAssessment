#include "MathFuncs.h"

namespace MathFuncs
{
#pragma region Vector2
	Vector2::Vector2()
	{
		x = 0;
		y = 0;
		values[0] = 0;
		values[1] = 0;
	}

	Vector2::Vector2(const Vector2 & other)
	{
		x = other.x;
		y = other.y;
		*values = *other.values;
	}
	
	Vector2::~Vector2()
	{
		
	}

	Vector2::Vector2(const float _x, const float _y)
	{
		
		x = _x;
		y = _y;
		values[0] = 0;
		values[1] = 0;
	}

	Vector2::Vector2(const float _x)
	{
		
		x = _x;
		y = 0;
		values[0] = 0;
		values[1] = 0;
	}

	float Vector2::Dot(Vector2 rhs)
	{
		return (x*rhs.x) + (y*rhs.y);
	}

	float Vector2::Magnitude()
	{
		return Mag(Vector4(x,y));
	}

	Vector2 Vector2::Normalize()
	{
		Vector4 temp = Norm(Vector4(x, y));
		return Vector2(temp.x, temp.y);
	}

	Vector2 Vector2::operator+(const Vector2 rhs)
	{
		Vector2 temp;
		temp.x = x + rhs.x;
		temp.y = y + rhs.y;
		return temp;
	}

	Vector2 Vector2::operator-(const Vector2 rhs)
	{
		Vector2 temp;
		temp.x = x - rhs.x;
		temp.y = y - rhs.y;
		return temp;
	}

	Vector2 Vector2::operator*(const float f)
	{
		Vector2 temp;
		temp.x = x * f;
		temp.y = y * f;
		return temp;
	}

	Vector2::operator float*()
	{
		values[0] = x;
		values[1] = y;
		return values;
	}
	
	Vector2 operator*(float lhs, Vector2 rhs)
	{
		Vector2 temp;
		temp.x = rhs.x * lhs;
		temp.y = rhs.y * lhs;
		return temp;
	}
#pragma endregion

#pragma region Vector3
	Vector3::Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
	}
	Vector3::Vector3(const Vector3 & other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		*values = *other.values;
	}
	Vector3::Vector3(const float _x, const float _y, const float _z)
	{
		x = _x;
		y = _y;
		z = _z;
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
	}

	Vector3::Vector3(const float _x, const float _y)
	{
		x = _x;
		y = _y;
		z = 0;
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
	}

	Vector3::Vector3(const float _x)
	{
		x = _x;
		x = _x;
		y = 0;
		z = 0;
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
	}
	float Vector3::Dot(Vector3 rhs)
	{
		return (x*rhs.x) + (y*rhs.y) + (z*rhs.z);
	}
	Vector3 Vector3::Cross(Vector3 rhs)
	{
		return Vector3((y*rhs.z)-(z*rhs.y),(z*rhs.x)-(x*rhs.z),(x*rhs.y)-(y*rhs.x));
	}
	float Vector3::Magnitude()
	{
		return Mag(Vector4(x, y, z));
	}
	Vector3 Vector3::Normalize()
	{
		Vector4 temp = Norm(Vector4(x, y, z));
		return Vector3(temp.x,temp.y,temp.z);
	}
	Vector3 Vector3::operator+(const Vector3 rhs)
	{
		Vector3 temp;
		temp.x = x + rhs.x;
		temp.y = y + rhs.y;
		temp.z = z + rhs.z;
		return temp;
	}
	Vector3 Vector3::operator-(const Vector3 rhs)
	{
		Vector3 temp;
		temp.x = x - rhs.x;
		temp.y = y - rhs.y;
		temp.z = z - rhs.z;
		return temp;
	}
	Vector3 Vector3::operator*(const float f)
	{
		Vector3 temp;
		temp.x = x * f;
		temp.y = y * f;
		temp.z = z * f;
		return temp;
	}
	Vector3::operator float*()
	{
		values[0] = x;
		values[1] = y;
		values[2] = z;
		return values;
	}
	Vector3::~Vector3()
	{

	}

	Vector3 operator*(float lhs, Vector3 rhs)
	{
		Vector3 temp;
		temp.x = rhs.x * lhs;
		temp.y = rhs.y * lhs;
		temp.z = rhs.z * lhs;
		return temp;
	}
#pragma endregion 

#pragma region Vector4
	Vector4::Vector4()
	{
		x = 0;
		y = 0;
		z = 0;
		w = 0;
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
		values[3] = 0;
	}
	Vector4::Vector4(const Vector4 & other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		*values = *other.values;
	}
	Vector4::~Vector4()
	{

	}

	Vector4::Vector4(const float _x, const float _y, const float _z, const float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
		values[3] = 0;
	}

	Vector4::Vector4(const float _x, const float _y, const float _z)
	{
		x = _x;
		y = _y;
		z = _z;
		w = 0;
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
		values[3] = 0;
	}

	Vector4::Vector4(const float _x, const float _y)
	{
		x = _x;
		y = _y;
		z = 0;
		w = 0;
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
		values[3] = 0;
	}

	Vector4::Vector4(const float _x)
	{
		x = _x;
		y = 0;
		z = 0;
		w = 0;
		values[0] = 0;
		values[1] = 0;
		values[2] = 0;
		values[3] = 0;
	}

	float Vector4::Dot(Vector4 rhs)
	{
		return (x*rhs.x) + (y*rhs.y) + (z*rhs.z) + (w*rhs.w);
	}

	Vector4 Vector4::Cross(Vector4 rhs)
	{
		//TODO: figure out what to do with w
		return Vector4((y*rhs.z) - (z*rhs.y), (z*rhs.x) - (x*rhs.z), (x*rhs.y) - (y*rhs.x), w);
	}

	float Vector4::Magnitude()
	{
		return Mag(Vector4(x,y,z,w));
	}

	Vector4 Vector4::Normalize()
	{
		return Norm(Vector4(x, y, z, w));
	}

	Vector4 Vector4::operator+(const Vector4 rhs)
	{
		Vector4 temp;
		temp.x = x + rhs.x;
		temp.y = y + rhs.y;
		temp.z = z + rhs.z;
		temp.w = w + rhs.w;
		return temp;
	}

	Vector4 Vector4::operator-(const Vector4 rhs)
	{
		Vector4 temp;
		temp.x = x - rhs.x;
		temp.y = y - rhs.y;
		temp.z = z - rhs.z;
		temp.w = w - rhs.w;
		return temp;
	}

	Vector4 Vector4::operator*(const float f)
	{
		Vector4 temp;
		temp.x = x * f;
		temp.y = y * f;
		temp.z = z * f;
		temp.w = w * f;
		return temp;
	}

	Vector4::operator float*()
	{
		values[0] = x;
		values[1] = y;
		values[2] = z;
		values[3] = w;
		return values;
	}

	Vector4 operator*(float lhs, Vector4 rhs)
	{
		Vector4 temp;
		temp.x = rhs.x * lhs;
		temp.y = rhs.y * lhs;
		temp.z = rhs.z * lhs;
		temp.w = rhs.w * lhs;
		return temp;
	}
	Vector2 operator*(const Matrix2 lhs, const Vector2 rhs)
	{
		Vector2 ans;
		ans.x = (rhs.x*lhs.value[0][0]) + (rhs.y * lhs.value[1][0]);
		ans.y = (rhs.x * lhs.value[0][1]) + (rhs.y * lhs.value[1][1]);
		return ans;
	}
#pragma endregion

#pragma region Matrix2
	Matrix2::Matrix2()
	{
		value[0][0] = 0;
		value[1][0] = 0;
		value[0][1] = 0;
		value[1][1] = 0;
	}

	Matrix2::Matrix2(const Matrix2 & other)
	{
		value[0][0] = other.value[0][0];
		value[1][0] = other.value[1][0];
		value[0][1] = other.value[0][1];
		value[1][1] = other.value[1][1];
	}

	Matrix2::~Matrix2()
	{
	}

	Matrix2::Matrix2(const float _x, const float _y, const float _z, const float _w)
	{
		value[0][0] = _x;
		value[1][0] = _y;

		value[0][1] = _z;
		value[1][1] = _w;
	}

	Matrix2 Matrix2::SetRotateZ(float theta)
	{
		return Matrix2(cos(theta),-sin(theta),sin(theta),cos(theta));
	}

	Matrix2 Matrix2::operator*(const Matrix2 rhs)
	{
		///steps
		// a[2,2] * b[2,2] = c[2,2]
		//crate array which is mat [a.colum][mat b.row]
		//the first entry (ie. c[0,0]) will be (a[0,0] * b[0,0]) + (a[1,0] * b[0,1])
		//the second (ie. c[0,1]) will be (a[0,0] * b[1,0]) + (a[1,0] * b[1,1])
		//and so on
		Matrix2 ans = Matrix2();
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				for (int k = 0; k < 2; ++k)
				{
					ans.value[i][j] += value[i][k] * rhs.value[k][j];
				}
			}
		}
		return ans;
	}

	Matrix2::operator float*()
	{
		return (float*)value;
	}

#pragma endregion

#pragma region Matrix3
	Matrix3::Matrix3()
	{
		value[0][0] = 0;
		value[1][0] = 0;
		value[2][0] = 0;

		value[0][1] = 0;
		value[1][1] = 0;
		value[2][1] = 0;

		value[0][2] = 0;
		value[1][2] = 0;
		value[2][2] = 0;
	}

	Matrix3::Matrix3(const Matrix3 & other)
	{
		value[0][0] = other.value[0][0];
		value[1][0] = other.value[1][0];
		value[2][0] = other.value[2][0];

		value[0][1] = other.value[0][1];
		value[1][1] = other.value[1][1];
		value[2][1] = other.value[2][1];

		value[0][2] = other.value[0][2];
		value[1][2] = other.value[1][2];
		value[2][2] = other.value[2][2];
	}

	Matrix3::~Matrix3()
	{
	}

	Matrix3::Matrix3(const float a, const float b, const float c, const float d, const float e, const float f, const float g, const float h, const float i)
	{
		value[0][0] = a;
		value[1][0] = b;
		value[2][0] = c;

		value[0][1] = d;
		value[1][1] = e;
		value[2][1] = f;

		value[0][2] = g;
		value[1][2] = h;
		value[2][2] = i;
	}

	Matrix3 Matrix3::SetRotateX(float theta)
	{
		return Matrix3( 1,0,0,
						0,cos(theta),-sin(theta),
						0,sin(theta),cos(theta));
	}

	Matrix3 Matrix3::SetRotateY(float theta)
	{
		return Matrix3( cos(theta) ,0,sin(theta),
						0		   ,1,0,
						-sin(theta),0,cos(theta));
	}

	Matrix3 Matrix3::SetRotateZ(float theta)
	{
		return Matrix3( cos(theta), -sin(theta),0, 
						sin(theta),  cos(theta),0,
						0		  ,0           ,1);
	}

	Matrix3 Matrix3::operator*(const Matrix3 rhs)
	{
		Matrix3 ans = Matrix3();
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				for (int k = 0; k < 3; ++k)
				{
					ans.value[i][j] += value[i][k] * rhs.value[k][j];
				}
			}
		}
		return ans;
	}

	Matrix3::operator float*()
	{
		return (float*)value;
	}

#pragma endregion

#pragma region Matrix4
	Matrix4::Matrix4()
	{
		value[0][0] = 0;
		value[1][0] = 0;
		value[2][0] = 0;
		value[3][0] = 0;

		value[0][1] = 0;
		value[1][1] = 0;
		value[2][1] = 0;
		value[3][1] = 0;

		value[0][2] = 0;
		value[1][2] = 0;
		value[2][2] = 0;
		value[3][2] = 0;

		value[0][3] = 0;
		value[1][3] = 0;
		value[2][3] = 0;
		value[3][3] = 0;
	}

	Matrix4::Matrix4(const Matrix4 & other)
	{
		value[0][0] = other.value[0][0];
		value[1][0] = other.value[1][0];
		value[2][0] = other.value[2][0];
		value[3][0] = other.value[3][0];

		value[0][1] = other.value[0][1];
		value[1][1] = other.value[1][1];
		value[2][1] = other.value[2][1];
		value[3][1] = other.value[3][1];

		value[0][2] = other.value[0][2];
		value[1][2] = other.value[1][2];
		value[2][2] = other.value[2][2];
		value[3][2] = other.value[3][2];

		value[0][3] = other.value[0][3];
		value[1][3] = other.value[1][3];
		value[2][3] = other.value[2][3];
		value[3][3] = other.value[3][3];
	}

	Matrix4::~Matrix4()
	{
	}

	Matrix4::Matrix4(const float a, const float b, const float c, const float d, 
					 const float e, const float f, const float g, const float h, 
					 const float i, const float j, const float k, const float l, 
					 const float m, const float n, const float o, const float p)
	{
		value[0][0] = a;
		value[1][0] = b;
		value[2][0] = c;
		value[3][0] = d;

		value[0][1] = e;
		value[1][1] = f;
		value[2][1] = g;
		value[3][1] = h;

		value[0][2] = i;
		value[1][2] = j;
		value[2][2] = k;
		value[3][2] = l;

		value[0][3] = m;
		value[1][3] = n;
		value[2][3] = o;
		value[3][3] = p;
	}

	Matrix4 Matrix4::SetRotateX(float theta)
	{
		return Matrix4(
			1, 0, 0, 0,
			0, cos(theta), -sin(theta), 0,
			0, sin(theta), cos(theta), 0,
			0, 0, 0, 1);
	}

	Matrix4 Matrix4::SetRotateY(float theta)
	{
		return Matrix4(
			cos(theta), 0, sin(theta), 0,
			0, 1, 0, 0,
			-sin(theta), 0, cos(theta), 0,
			0, 0, 0, 1);
	}

	Matrix4 Matrix4::SetRotateZ(float theta)
	{
		return Matrix4( 
			cos(theta), -sin(theta), 0, 0,
			sin(theta), -cos(theta), 0, 0,
			0		  , 0          , 1, 0,
			0		  , 0		   , 0, 1);
	}

	Matrix4 Matrix4::operator*(const Matrix4 rhs)
	{
		Matrix4 ans = Matrix4();
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				for (int k = 0; k < 4; ++k)
				{
					ans.value[i][j] += value[i][k] * rhs.value[k][j];
				}
			}
		}
		return ans;
	}
	Matrix4::operator float*()
	{
		return (float*)value;
	}
#pragma endregion

#pragma region AgnosticFuncs
	float Mag(const Vector4 vec)
	{
		return sqrt((vec.x*vec.x) + (vec.y*vec.y) + (vec.z*vec.z) + (vec.w*vec.w));
	}
	Vector4 Norm(const Vector4 vec)
	{
		Vector4 temp = Vector4(vec.x, vec.y, vec.z, vec.w);
		float mag = temp.Magnitude();
		return Vector4(temp.x / mag, temp.y / mag, temp.z / mag, temp.w / mag);
	}
#pragma endregion
}