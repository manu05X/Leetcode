/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let currCounter = init;
    return {
        increment : function() {
            currCounter += 1;
            return currCounter;
        },

        decrement : function(){
            currCounter -= 1;
            return currCounter;
        },

        reset : function(){
            currCounter = init;
            return currCounter;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */