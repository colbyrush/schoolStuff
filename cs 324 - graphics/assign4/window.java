public class window
{
   double vpxMin;
   double vpyMin;
   double vpxMax;
   double vpyMax;

   double winMinX;
   double winMinY;
   double winMinZ;
   double winMaxX;
   double winMaxY;
   double winMaxZ;

    public window()
    {
	vpxMin = 0.0;
	vpyMin = 0.0;
	vpxMax = 0.0;
	vpyMax = 0.0;

	winMinX = 0.0;
	winMinY = 0.0;
	winMinZ = 0.0;
	winMaxX = 0.0;
	winMaxY = 0.0;
	winMaxZ = 0.0;
    }
    
    public void getWindow( double vxmin, double vymin, double vxmax, double vymax,
		     point min, point max )
    {
	vpxMin = vxmin;
	vpyMin = vymin;
	vpxMax = vxmax;
	vpyMax = vymax;

	winMinX = min.GetX();
	winMaxY = min.GetY();
	winMinZ = min.GetZ();
	winMaxX = max.GetX();
	winMaxY = max.GetY();
	winMaxZ = max.GetZ();
    }

}