class ParkingSystem {

    int [] arr = new int[3];
    public ParkingSystem(int big, int medium, int small) {
        this.arr[0] = big;
        this.arr[1] = medium;
        this.arr[2] = small;
    }
    
    public boolean addCar(int carType) {
        return arr[carType-1]-- > 0; 
    }
}

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem obj = new ParkingSystem(big, medium, small);
 * boolean param_1 = obj.addCar(carType);
 */