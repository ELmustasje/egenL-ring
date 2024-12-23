var small = 1;
var medium = 2;
var large = 3;
//PascallCase
var Size;
(function(Size) {
  Size[Size["Small"] = 1] = "Small";
  Size[Size["Medium"] = 2] = "Medium";
  Size[Size["Large"] = 3] = "Large";
})(Size || (Size = {}));
var mysize = Size.Small;
console.log(mysize);
