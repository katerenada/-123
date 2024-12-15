#include <stdio.h>
#include <stdlib.h>

typedef struct element {   // تعريف بنية بيانات 
    int val;   // المتغير val لتخزين القيمة الموجودة في العنصر.
    struct element *suivant;  // مؤشر إلى العنصر التالي في القائمة.
} element;

element *creerListe() {   // دالة لإنشاء قائمة مرتبطة فارغة.
    return NULL;   // إرجاع NULL لأن القائمة فارغة في البداية.
}

element *chargerListe(int Tab[], int n, element *liste) {    // دالة لتحميل عناصر من المصفوفة إلى القائمة.
    for (int i = n - 1; i >= 0; i--) {   // تكرار من آخر عنصر في المصفوفة حتى أولها.
        element *nouveau = (element*)malloc(sizeof(element));   // تخصيص ذاكرة لعنصر جديد في الذاكرة.
        nouveau->val = Tab[i]; // تعيين قيمة العنصر الجديد من المصفوفة.
        nouveau->suivant = liste;  // ربط العنصر الجديد بالقائمة السابقة (بداية القائمة).
        liste = nouveau;   // تحديث رأس القائمة ليشير إلى العنصر الجديد.
    }
    return liste;  // إرجاع رأس القائمة بعد تحميل جميع العناصر.
}

void afficherListe(element *liste) {  // دالة لعرض محتويات القائمة.
    while (liste != NULL) {     while (liste != NULL) {  // استمر في عرض العناصر حتى الوصول إلى نهاية القائمة.
        printf("%d ", liste->val);  // طباعة قيمة العنصر الحالي.
        liste = liste->suivant;   // الانتقال إلى العنصر التالي في القائمة.
    }
    printf("\n");  // طباعة سطر جديد بعد عرض جميع العناصر.
}

element *supprimerEnFin(element *liste) {  // دالة لحذف العنصر الأخير من القائمة.
    if (liste == NULL) {  //  .NULLإذا كانت القائمة فارغة، أعد
        return NULL;
    }
    if (liste->suivant == NULL) {   // إذا كانت القائمة تحتوي على عنصر واحد فقط.
        free(liste);  // تحرير الذاكرة المخصصة للعنصر الوحيد.
        return NULL;  // NULL لأن القائمة أصبحت فارغة أعد 
    }
    element *tmp = liste;   // تعريف مؤشر مؤقت للانتقال عبر العناصر.
    while (tmp->suivant->suivant != NULL) {  // البحث عن العنصر الذي يسبق العنصر الأخير.
        tmp = tmp->suivant;  // الانتقال إلى العنصر التالي.
    }
    free(tmp->suivant); // تحرير الذاكرة المخصصة للعنصر الأخير.
    tmp->suivant = NULL;  // تعيين العنصر قبل الأخير ليكون العنصر الأخير (بإلغاء رابط العنصر الأخير).
    return liste;   // إرجاع رأس القائمة بعد حذف العنصر الأخير.
}

element *ajouterEnDebut(element *liste, int valeur) {  // دالة لإضافة عنصر في بداية القائمة.
    element *nouveau = (element*)malloc(sizeof(element));  // تخصيص ذاكرة لعنصر جديد. 
    nouveau->val = valeur;  // تعيين القيمة المدخلة للعنصر الجديد.
    nouveau->suivant = liste;  // ربط العنصر الجديد ببداية القائمة الحالية. 
    return nouveau;  // إرجاع رأس القائمة الجديد (الذي هو العنصر الجديد الآن).
}

void viderListe(element *liste) {  // دالة لتحرير جميع العناصر في القائمة.
    while (liste != NULL) {  // استمر في المرور عبر العناصر حتى الوصول إلى نهاية القائمة.
        element *tmp = liste;  // حفظ المؤشر الحالي.
        liste = liste->suivant;  // الانتقال إلى العنصر التالي.
        free(tmp);  // تحرير الذاكرة المخصصة للعنصر الحالي.
    }
}

int main() {
    int Tab[10] = {1, 3, 5, 7, 8, 10, 9, 11, 13, 20};
    element *liste = creerListe();
    liste = chargerListe(Tab, 10, liste);

    afficherListe(liste);

    element *L1 = supprimerEnFin(liste);
    afficherListe(L1);

    element *L2 = ajouterEnDebut(L1, 40);
    afficherListe(L2);

    viderListe(L2);

    return 0;
}
