class UndergroundSystem {
    private Map<String, Pair<Integer, Integer>> journeyData = new HashMap<>();
    private Map<Integer, Pair<String, Integer>> checkInData = new HashMap<>();
    
    public UndergroundSystem() {
        
    }
    
    public void checkIn(int id, String stationName, int t) {
        checkInData.put(id, new Pair<>(stationName,t));
    }
    
    public void checkOut(int id, String stationName, int t) {
          // Look up the check in station and check in time for this id.
        Pair<String, Integer> checkInId = checkInData.get(id);
        String startStation = checkInId.getKey();
        Integer checkInTime = checkInId.getValue();
        
         // Lookup the current travel time data for this route.
        String route = startStation + "-" + stationName;
        Pair<Integer, Integer> routeStats = journeyData.getOrDefault(route, new Pair<>(0,0));
        Integer totalTripTime = routeStats.getKey();
        Integer totalTrips = routeStats.getValue();
        
        // Update the travel time data with this trip.
        Integer tripTime = t - checkInTime;
        journeyData.put(route, new Pair<>(tripTime + totalTripTime, totalTrips+1));
        
    }
    
    public double getAverageTime(String startStation, String endStation) {
        String route = startStation + "-" + endStation;
        // Lookup how many times this route journey has been made, and the total time.
        Pair<Integer, Integer> checkout = journeyData.get(route);
        Integer totalTime = checkout.getKey();
        Integer totalTrips = checkout.getValue();
         // The average is simply the total divided by the number of trips.
        return (double) totalTime / totalTrips;
        
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */