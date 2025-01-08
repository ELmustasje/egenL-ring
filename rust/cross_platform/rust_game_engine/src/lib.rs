use jni::objects::JClass;
use jni::sys::{jint, jintArray};
use jni::JNIEnv;

#[no_mangle]
pub extern "system" fn Java_GameEngine_test1(
    _env: JNIEnv,   // JNI environment pointer
    _class: JClass, // Reference to the calling class
    a: jint,
) -> jint {
    for i in 0..10_000_000 {
        for j in 0..10 {
            let a = i ^ j;
        }
    }
    10
}

#[no_mangle]
pub extern "system" fn Java_GameEngine_test2(
    env: JNIEnv,    // JNI environment pointer
    _class: JClass, // Reference to the calling class
    a: jintArray,
) -> jintArray {
    let length = env.get_array_length(a).unwrap();

    let mut rust_arr = vec![0; length as usize];
    env.get_int_array_region(a, 0, &mut rust_arr).unwrap();

    let provessed_arr: Vec<jint> = rust_arr.iter().map(|&x| x * 2).collect();

    let output_array = env.new_int_array(length).unwrap();
    env.set_int_array_region(output_array, 0, &provessed_arr)
        .unwrap();

    output_array
}
