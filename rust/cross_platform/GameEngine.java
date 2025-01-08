public class GameEngine {
    static {
        System.load("/home/thomasbarth/egenL-ring/rust/cross_platform//rust_game_engine/target/release/librust_game_engine.so"); // Load the Rust library
    }

    // Native methods
    public native int test1(int a); // Returns a pointer to the Rust GameEngine instance
    public native int[] test2(int[] a);

    public static void main(String[] args) {

        GameEngine engine = new GameEngine();
        int len = 99999999;
        int[] input_arr = createArray(len);

        long start = System.currentTimeMillis();
        int[] res = engine.test2(input_arr);
        long end = System.currentTimeMillis();
        System.out.println(end - start);

        input_arr = createArray(len);
        start = System.currentTimeMillis();
        for(int i = 0; i < len; i++){
          input_arr[i] = input_arr[i] * 2;
        }
        end = System.currentTimeMillis();
        System.out.println(end - start);
        
      

    }
    public static int[] createArray(int x) {
        // Create an array of length x
        int[] array = new int[x];

        // Fill the array with 1
        for (int i = 0; i < x; i++) {
            array[i] = 1;
        }

        return array;
    }

}
