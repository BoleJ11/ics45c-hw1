double knots_to_miles_per_minute(int knot) {
    double milesperhour = 6076.0 / 5280.0;
    double knotpermin = milesperhour / 60.0;
    return knot * knotpermin;
}
