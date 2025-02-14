class ProductOfNumbers {
    List<Integer> prefixProduct = new ArrayList<>();
    int sz = 0;

    public ProductOfNumbers() {
        this.prefixProduct.add(1);
        this.sz = 0;
    }
    
    public void add(int num) {
        if(num == 0){
            this.prefixProduct = new ArrayList<Integer>();
            this.prefixProduct.add(1);
            this.sz = 0;
        } else {
            this.prefixProduct.add(this.prefixProduct.get(sz) * num);
            sz++;
        }
    }
    
    public int getProduct(int k) {
        if(k > this.sz){
            return 0;
        }

        return this.prefixProduct.get(this.sz)/this.prefixProduct.get(this.sz-k);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */