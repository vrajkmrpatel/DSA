function rotateRight(arr, k, n) {


    while (k > 0) {

        var temp = arr[n - 1];

        for (let i = n - 1; i > 0; i--) {

            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
        k--;
    }
}

function rotateLeft(arr, k, n) {

    while (k > 0) {

        var temp = arr[0];
        for (let i = 0; i < n - 1; i++) {

            arr[i] = arr[i + 1];
        }
        arr[n - 1] = temp;
        k--;
    }
}

var arr = [1, 2, 3, 4, 5];
var n = arr.length;
var k = 2;


console.log("Noramal Array", arr);
rotateRight(arr, k, n);
console.log("Rotating Clockwise", k, " Position", arr);
rotateLeft(arr, k, n);
console.log("Rotating AntiClockwise", k, " Position", arr);








