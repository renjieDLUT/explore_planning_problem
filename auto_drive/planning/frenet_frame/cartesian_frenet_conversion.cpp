#include"cartesian_frenet_conversion.h"
#include<iostream>
#include <cmath>
using namespace std;

void CartesianFrenetConverter::cartesian_to_frent(const double rs, const double rx, const double ry, const double rtheta, const double rkappa, const double rdkappa,
	const double x, const double y, const double v, const double a, const double theta, const double kappa)
{
	 double s_condition[3] = {0 ,0, 0};
	 double d_condition[3] = {0 ,0, 0};


	const double dx = x - rx;
	const double dy = y - ry;

	const double cos_theta_r = cos(rtheta);
	const double sin_theta_r = sin(rtheta);

	const double cross_rd_nd = cos_theta_r * dy - sin_theta_r * dx;

	 d_condition[0]= copysign(std::sqrt(dx * dx + dy * dy), cross_rd_nd);

	const double delta_theta = theta - rtheta;
	const double tan_delta_theta = tan(delta_theta);
	const double cos_delta_theta = cos(delta_theta);

	const double one_minus_kappa_r_d = 1 - rkappa * d_condition[0];
	d_condition[1] = one_minus_kappa_r_d * tan_delta_theta;
	const double kappa_r_d_prime = rdkappa * d_condition[0] + rkappa * d_condition[1];

	d_condition[2] = (-kappa_r_d_prime * tan_delta_theta +one_minus_kappa_r_d / cos_delta_theta / cos_delta_theta *(kappa * one_minus_kappa_r_d / cos_delta_theta - rkappa));
	s_condition[1] = rs;
	s_condition[1] = v * cos_delta_theta / one_minus_kappa_r_d;
	const double delta_theta_prime = one_minus_kappa_r_d / cos_delta_theta * kappa - rkappa;
	s_condition[2] = ((a * cos_delta_theta -s_condition[1] * s_condition[1] *(d_condition[1] * delta_theta_prime - kappa_r_d_prime))/one_minus_kappa_r_d);
	//return s_condition[], d_condition[];  //C++不能返回数组，需要定义一个指向数组的指针，返回指针的地址
}

void  CartesianFrenetConverter::frent_to_cartesian(const double rs, const double rx, const double ry, const double rtheta, const double rkappa, const double rdkappa,
												const double s_condition[3], const double d_condition[3])
{
	if (fabs(rs - s_condition[0]) > 0.001)
	{
		printf("The reference point s and s_condition[0] don't match");
	}

		
	const double	cos_theta_r = cos(rtheta);
	const double    sin_theta_r = sin(rtheta);

	const double x = rx - sin_theta_r * d_condition[0];
	const double y = ry + cos_theta_r * d_condition[0];

	const double one_minus_kappa_r_d = 1 - rkappa * d_condition[0];
	const double tan_delta_theta = d_condition[1] / one_minus_kappa_r_d;
	const double delta_theta = atan2(d_condition[1], one_minus_kappa_r_d);
	const double cos_delta_theta = cos(delta_theta);

	const double theta = 0;//NormalizeAngle(delta_theta + rtheta);  //C++归一化函数？
	const double kappa_r_d_prime = rdkappa * d_condition[0] + rkappa * d_condition[1];

	const double kappa = ((((d_condition[2] + kappa_r_d_prime * tan_delta_theta) *
		cos_delta_theta * cos_delta_theta) /(one_minus_kappa_r_d)+rkappa) * cos_delta_theta / (one_minus_kappa_r_d));

	const double d_dot = d_condition[1] * s_condition[1];

	const double v = sqrt(one_minus_kappa_r_d * one_minus_kappa_r_d * s_condition[1] * s_condition[1] + d_dot * d_dot);
	const double delta_theta_prime = one_minus_kappa_r_d / cos_delta_theta * (kappa)-rkappa;

	const double a = (s_condition[2] * one_minus_kappa_r_d / cos_delta_theta +
		s_condition[1] * s_condition[1] / cos_delta_theta *
		(d_condition[1] * delta_theta_prime - kappa_r_d_prime));
	//return x, y, v, a, theta, kappa;
}


int main()
{
	
	
	return 0;
}