/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */

class counter {
    constructor(init){
        this.init = init;
        this.currCounter = init;
    }

    increment(init){
        this.currCounter+=1;
        return this.currCounter;
    }

    reset(init){
        this.currCounter = this.init;
        return this.currCounter;
    }

    decrement(init){
        this.currCounter -=1;
        return this.currCounter;
    }

}

var createCounter = function(init) {
    return new counter(init);
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */

//  toBe(val2){
//         if(this.val !== val2){
//             throw new Error("Not Equal");
//         }
//         return true;
//     }