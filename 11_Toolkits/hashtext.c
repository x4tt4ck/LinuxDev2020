#include <glib.h>
#include <stdio.h>

void
print_it(gpointer key, gpointer value, gpointer user_data)
{
    printf(user_data, key, value);
}

int
main(int argc, char **argv)
{
    if(argc == 1) {
        printf("Usage: %s FILE\n", argv[0]);
        return -1;
    }

    gchar* line = NULL;
    GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
    gsize length;
    gchar *content, *filename = argv[1];

    if (g_file_get_contents(filename, &content, &length, NULL)) {

        printf("[*] Loaded input file %s of length %d\n", argv[1], (int)length);
        gchar **split_content = g_strsplit(content, "\n", -1);

        for(gchar **i = split_content; *i; i++) {
            line = *i;
            gchar **split_line = g_strsplit(line, " ", -1);

            for(gchar **j = split_line; *j; j++) {
                gpointer x = g_hash_table_lookup(hash, *j);

                if(x != NULL) {
                    g_hash_table_replace(hash, *j, x+1);
                } else {
                    g_hash_table_insert(hash, *j, (gpointer) 1);
                }

            }

        }

        g_free(content);
        g_hash_table_foreach(hash, print_it, "Word '%s' appears %d times in the given file.\n");
    }

    return 0;
}
