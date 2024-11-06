#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
 
int main() {
  // Déclaration des constantes
  double const G = 6.67e-11;
  double const M = 5.96e24;
  double const R = 6.37e6;

  // Déclaration des variables
  double m, h, F, W, d, theta_deg, theta_rad;

  // Saisie des données par l'utilisateur
  cout << "Entrez la masse du corps (en kg): ";
  cin >> m;

  cout << "Entrez la hauteur de chute du corps (en m): ";
  cin >> h;

  cout << "Entrez la distance parcourue (en m): ";
  cin >> d;

  cout << "Entrez l'angle d'inclinaison (en degrés): ";
  cin >> theta_deg;

  // Conversion de l'angle en radians
  theta_rad = theta_deg * M_PI / 180.0;

  // Calcul de la force de gravité
  F = G * m * M / pow(R + h, 2);

  // Calcul du travail physique
  W = F * d * cos(theta_rad);

  // Affichage des résultats
  cout << fixed << setprecision(2); // Pour afficher deux chiffres après la virgule

  cout << "La force de gravité est : " << F << " N" << endl;
  cout << "Le travail physique est : " << W << " J" << endl;

  return 0;
}





/*
#def calculer_k1_k2():

    Calcule k1 et k2 à partir de deux vecteurs X et Y saisis par l'utilisateur

    while True:

        try:
            X = list(map(int, input("Entrez les 5 éléments du vecteur X séparés par des espaces (valeurs entre 10 et 100) : ").split()))

            Y = list(map(int, input("Entrez les 5 éléments du vecteur Y séparés par des espaces (valeurs entre 10 et 100) : ").split()))

            if len(X) != 5 or len(Y) != 5:
                raise ValueError("Les vecteurs doivent contenir exactement 5 éléments.")

            if not all(10 <= val <= 100 for val in X + Y):
                raise ValueError("Les valeurs doivent être comprises entre 10 et 100.")

            break
        except ValueError as e:

            print(f"Erreur : {e}")

    x_bar = np.mean(X)
    y_bar = np.mean(Y)

    k1 = (x_bar * min(X)) / (y_bar * max(Y))

    sum_x_squared = sum(x**2 for x in X)

    sum_x_times_y = sum(x * y for x, y in zip(X, Y))

    sum_x = sum(X)

    k2 = (sum_x_squared - sum_x_times_y) / (sum_x**2)

    print(f"k1 = {k1}")

    print(f"k2 = {k2}")

*/