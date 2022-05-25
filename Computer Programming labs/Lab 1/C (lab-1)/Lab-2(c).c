#include <stdio.h>
#include <math.h>

int main(void)
{
// declaring variables//
double q,w,e,r;
double heaviestprice;
double heaviestweight;
double lightestweight;
double lightestprice;
double totalprice;
double per_kg =59.26;
// asking the weight of every gold nuggets//
printf("Please give the weight of 1st gold nuggets\n");
scanf("%lf", &q);
printf("Please give the weight of 2nd gold nuggets\n");
scanf("%lf", &w);
printf("Please give the weight of 3rd gold nuggets\n");
scanf("%lf", &e);
printf("Please give the weight of 4th gold nuggets\n");
scanf("%lf", &r);


//checking condition for the lightestweight//

  if(q<=w && q<=e && q<=r)
  {
  lightestweight = q;
  }


  if(w<=q && w<=e && w<=r)
  {
    lightestweight = w;
  }


  if(e<=q && e<=w && e<=r)
  {
    lightestweight = e;
  }


  if(r<=q && r<=e && r<=w)
  {
    lightestweight = r;
  }
// checking condition for heaviestweight//

if(q>=w && q>=e && q>=r)
{
  heaviestweight = q;
  }


if(w>=q && w>=e && w>=r)
{
  heaviestweight = w;
  }

if(e>=w && e>=q && e>=r)
{
  heaviestweight = e;
  }

{
if(r>=w && r>=e && r>=q)
{
  heaviestweight = r;
  }
// declaring the formula to find out the price of heaviest gold nugget,lightest
//gold nugget and the total price.
//converting the gold nugget weight in grams because the price is giving in per
//gram.

heaviestprice = (heaviestweight)*(per_kg)*1000;
lightestprice = (lightestweight)*(per_kg)*1000;
totalprice = (q+w+e+r)*per_kg*1000;
printf("The lightestprice is %.2lf\n", lightestprice);
printf("The  heaviestweight is %.2lf\n", heaviestprice);

printf("The totalprice is %.2lf\n", totalprice);

return 0;
}
}
