mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}
        fn some_function() {}
    } /* hosting */
} /* front_of_house */

use crate::front_of_house::hosting;

pub fn eat_at_restaurant() {
    hosting::add_to_waitlist();
}

pub fn function_name() {
    hosting::add_to_waitlist();
}
