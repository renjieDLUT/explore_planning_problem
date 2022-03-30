#include"cartesian_frenet_conversion.h"
#include<iostream>
#include <cmath>
using namespace std;

void CartesianFrenetConverter::cartesian_to_frent(const double rs, const double rx, const double ry, const double rtheta, const double rkappa, const double rdkappa,
	const double x, const double y, const double v, const double a, const double theta, const double kappa,std::array<double, 3>* const ptr_s_condition,std::array<double, 3>* const ptr_d_condition)
{
	 double s_condition[3] = {0 ,0, 0};
	 double d_condition[3] = {0 ,0, 0};

    ptr_s_condition->at(0)=rs;

	const double dx = x - rx;
	const double dy = y - ry;

	const double cos_theta_r = cos(rtheta);
	const double sin_theta_r = sin(rtheta);

	const double cross_rd_nd = cos_theta_r * dy - sin_theta_r * dx;

	 d_condition[0]= copysign(std::sqrt(dx * dx + dy * dy), cross_rd_nd);
	 ptr_d_condition->at(0)=d_condition[0];

	const double delta_theta = theta - rtheta;
	const double tan_delta_theta = tan(delta_theta);
	const double cos_delta_theta = cos(delta_theta);

	const double one_minus_kappa_r_d = 1 - rkappa * d_condition[0];
	d_condition[1] = one_minus_kappa_r_d * tan_delta_theta;
	ptr_d_condition->at(1)=d_condition[1];
	const double kappa_r_d_prime = rdkappa * d_condition[0] + rkappa * d_condition[1];

	d_condition[2] = (-kappa_r_d_prime * tan_delta_theta +one_minus_kappa_r_d / cos_delta_theta / cos_delta_theta *(kappa * one_minus_kappa_r_d / cos_delta_theta - rkappa));
    ptr_d_condition->at(2)=d_condition[2];
	s_condition[1] = v * cos_delta_theta / one_minus_kappa_r_d;
	ptr_s_condition->at(1)=s_condition[1];
	const double delta_theta_prime = one_minus_kappa_r_d / cos_delta_theta * kappa - rkappa;
	s_condition[2] = ((a * cos_delta_theta -s_condition[1] * s_condition[1] *(d_condition[1] * delta_theta_prime - kappa_r_d_prime))/one_minus_kappa_r_d);
	ptr_s_condition->at(2)=s_condition[2];
    //return s_condition[], d_condition[];  //C++���ܷ������飬��Ҫ����һ��ָ�������ָ�룬����ָ��ĵ�ַ
}

void  CartesianFrenetConverter::frent_to_cartesian(const double rs, const double rx, const double ry, const double rtheta, const double rkappa, const double rdkappa,
												const double s_condition[3], const double d_condition[3],double &x, double &y,double &theta,double &kappa,double &v,double& a)
{
	if (fabs(rs - s_condition[0]) > 0.001)
	{
		printf("The reference point s and s_condition[0] don't match");
	}

	const double	cos_theta_r = cos(rtheta);
	const double    sin_theta_r = sin(rtheta);

	 x = rx - sin_theta_r * d_condition[0];
	 y = ry + cos_theta_r * d_condition[0];

	const double one_minus_kappa_r_d = 1 - rkappa * d_condition[0];
	const double tan_delta_theta = d_condition[1] / one_minus_kappa_r_d;
	const double delta_theta = atan2(d_condition[1], one_minus_kappa_r_d);
	const double cos_delta_theta = cos(delta_theta);

	theta = 0;//NormalizeAngle(delta_theta + rtheta);  //C++��һ��������
	const double kappa_r_d_prime = rdkappa * d_condition[0] + rkappa * d_condition[1];

	 kappa = ((((d_condition[2] + kappa_r_d_prime * tan_delta_theta) *
		cos_delta_theta * cos_delta_theta) /(one_minus_kappa_r_d)+rkappa) * cos_delta_theta / (one_minus_kappa_r_d));

	const double d_dot = d_condition[1] * s_condition[1];

	v = sqrt(one_minus_kappa_r_d * one_minus_kappa_r_d * s_condition[1] * s_condition[1] + d_dot * d_dot);
	const double delta_theta_prime = one_minus_kappa_r_d / cos_delta_theta * (kappa)-rkappa;

	a = (s_condition[2] * one_minus_kappa_r_d / cos_delta_theta +
		s_condition[1] * s_condition[1] / cos_delta_theta *
		(d_condition[1] * delta_theta_prime - kappa_r_d_prime));
}
