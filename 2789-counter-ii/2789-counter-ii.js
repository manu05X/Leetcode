/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let currCounter = init;
    return {
        increment : () => ++currCounter,

        decrement : ()=> --currCounter,

        reset : () => (currCounter = init),
        
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */