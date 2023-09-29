//
// Created by santi on 9/28/2023.
//

#ifndef FLOATCELL_FLOATCELL_H
#define FLOATCELL_FLOATCELL_H


class Floatcell {

    public:
        explicit Floatcell(float newValue = 0);
        Floatcell(const Floatcell &rhs);
        Floatcell(Floatcell &&rhs) noexcept;
        ~Floatcell() = default;

        Floatcell &operator=(const Floatcell &rhs);
        Floatcell &operator=(Floatcell &&rhs) noexcept;

        // Overloaded assignment operator to accept primitive int
        Floatcell &operator=(float rhs);

        float getValue() const;
        void setValue(float newValue);

    private:
        float storedValue;


};


#endif //FLOATCELL_FLOATCELL_H
