

/*笛卡尔坐标系与Frenet坐标系相互转换*/
/*参考博客
Apollo项目坐标系研究
https://blog.csdn.net/davidhopper/article/details/79162385
Apollo Lattice Planner从学习到放弃到实践
https://zhuanlan.zhihu.com/p/164635074
Frenet坐标系与Cartesian坐标系互转
https://blog.csdn.net/u013468614/article/details/108748016
*/
/*接口物理定义
Frenet坐标系：
rs：Frenet纵坐标
rs_dot:Frenet纵坐标对时间的导数，也即沿base frame的速度
rs_dot_dot:沿base frame的加速度；
l：Frenet横坐标；
l_dot:Frenet横向速度；
l_dot_dot:Frenet横向加速度；
l':Frenet横向坐标对纵向坐标的导数；
l'':Frenet横向坐标对纵向坐标的二阶导

Cartesian坐标系：
x:对应Cartesian坐标系下的坐标，是一个向量
theta_x:Cartesian坐标系下的朝向；
kappa:曲率；
vehicle_speed:Cartesian坐标系下的线速度；
accelerate_speed:Cartesian坐标系下的加速度；
*/
#include<array>
class CartesianFrenetConverter
{
public:
	CartesianFrenetConverter() = delete;
	static void frent_to_cartesian(const double rs, const double rx, const double ry, const double rtheta, const double rkappa, const double rdkappa,
		const double s_condition[3], const double d_condition[3],double &x, double &y,double &theta,double &kappa,double &v,double& a);
	static void cartesian_to_frent(const double rs, const double rx, const double ry, const double rtheta, const double rkappa, const double rdkappa,
		const double x, const double y, const double v, const double a, const double theta, const double k,std::array<double, 3>* const ptr_s_condition,std::array<double, 3>* const ptr_d_condition);
};


