using System;

namespace gravityspace
{
    public class gravity
    {
        public double X { get; set; }
        public double Y { get; set; }
        public double Z { get; set; }
        public double Weight { get; set; }
        public gravity(double x,double y,double z,double weight)
        {
            X = x;
            Y = y;
            Z = z;
            Weight = weight;
        }
        public gravity CenterOfMass(gravity[] startarray, gravity finalgravity)
        {
            int length = startarray.Length;
            double SumX = 0, SumY = 0, SumZ = 0, SumMass = 0;
            for (int i = 0; i < length; i++)
            {
                SumX += (startarray[i].X * startarray[i].Weight); // TODO: Исправить ошибку
                SumY += (startarray[i].Y * startarray[i].Weight);
                SumZ += (startarray[i].Z * startarray[i].Weight);
                SumMass += startarray[i].Weight;
            }
            finalgravity.X = SumX / SumMass;
            finalgravity.Y = SumY / SumMass;
            finalgravity.Z = SumZ / SumMass;
            finalgravity.Weight = SumMass;
            return finalgravity;
        }

        public void Print()
        {
            Console.WriteLine($"{this.X},{this.Y},{this.Z},{this.Weight}");
        }
    }

    public class TestClass
    {
        static void Main(string[] args)
        {
            var point1 = new gravity(1, 0, 0, 1);
            var point2 = new gravity(-2, 0, 0, 1);
            //var point3 = new gravity(-3*(Math.Sqrt(3)), -2 * (Math.Sqrt(3)), 0, 1);
            var point0 = new gravity(0, 0, 0, 0);
            var array = new gravity[3];
            array[0] = point1;
            array[1] = point2;
            //array[2] = point3;
            point0 = point0.CenterOfMass(array, point0);
            point0.Print();
        }
    }
}
