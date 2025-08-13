int altura(struct ab_int* root){
    if(!root)
        return 0;
        
    int altura_esq = altura(root->esq);
    int altura_dir = altura(root->dir);
    
    return 1 + (altura_esq > altura_dir ? altura_esq : altura_dir);
    
}
