

/*�ѿ�������ϵ��Frenet����ϵ�໥ת��*/
/*�ο�����
Apollo��Ŀ����ϵ�о�
https://blog.csdn.net/davidhopper/article/details/79162385
Apollo Lattice Planner��ѧϰ��������ʵ��
https://zhuanlan.zhihu.com/p/164635074
Frenet����ϵ��Cartesian����ϵ��ת
https://blog.csdn.net/u013468614/article/details/108748016
*/
/*�ӿ�������
Frenet����ϵ��
rs��Frenet������
rs_dot:Frenet�������ʱ��ĵ�����Ҳ����base frame���ٶ�
rs_dot_dot:��base frame�ļ��ٶȣ�
l��Frenet�����ꣻ
l_dot:Frenet�����ٶȣ�
l_dot_dot:Frenet������ٶȣ�
l':Frenet�����������������ĵ�����
l'':Frenet�����������������Ķ��׵�

Cartesian����ϵ��
x:��ӦCartesian����ϵ�µ����꣬��һ������
theta_x:Cartesian����ϵ�µĳ���
kappa:���ʣ�
vehicle_speed:Cartesian����ϵ�µ����ٶȣ�
accelerate_speed:Cartesian����ϵ�µļ��ٶȣ�
*/

class CartesianFrenetConverter
{
public:
	CartesianFrenetConverter() = delete;
	static void frent_to_cartesian(const double rs, const double rx, const double ry, const double rtheta, const double rkappa, const double rdkappa,
		const double s_condition[3], const double d_condition[3]);
	static void cartesian_to_frent(const double rs, const double rx, const double ry, const double rtheta, const double rkappa, const double rdkappa,
		const double x, const double y, const double v, const double a, const double theta, const double k);
};


