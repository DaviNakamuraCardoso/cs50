#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Davi's all locked graph, to keep track of loops
bool dalocked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;

    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    // Quickly test the application (comment out the main vote loop first)
    /*
    char *votes[9][3] = {
        {"Alice", "Bob", "Charlie"},
        {"Alice", "Bob", "Charlie"},
        {"Alice", "Bob", "Charlie"},
        {"Bob", "Charlie", "Alice"},
        {"Bob", "Charlie", "Alice"},
        {"Charlie", "Alice", "Bob"},
        {"Charlie", "Alice", "Bob"},
        {"Charlie", "Alice", "Bob"},
        {"Charlie", "Alice", "Bob"},
    };

    for (int i = 0; i < 9; i++)
    {
        int ranks[3] = {0};
        for (int j = 0; j < candidate_count; j++)
        {
            vote(j, votes[i][j], ranks);
        }
        record_preferences(ranks);
    }
    */


    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();

    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i]) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    
    for (int i = 0; i < candidate_count; i++)
    {
        int winner = ranks[i];

        for (int j = i + 1; j < candidate_count; j++)
        {
            int loser = ranks[j];
            preferences[winner][loser]++;
        }
    }


    return;
}

// Print preferences graph for debugging
void print_prefs(void)
{
    printf("[\n");
    for (int i = 0; i < candidate_count; i++)
    {
        printf("[");
        for (int j = 0; j < candidate_count; j++)
        {
            printf("%i, ", preferences[i][j]);
        }
        printf("]\n");
    }
    printf("]\n");
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int votes_a = preferences[i][j];
            int votes_b = preferences[j][i];

            if (votes_a > votes_b)
            {
                pairs[pair_count++] = (pair) {.winner=i, .loser=j};
            } 
        }
    } 
    return;
}

// Compare function for sorting
static int compare(const void* a, const void* b)
{
    pair pa = *(pair*)a;
    pair pb = *(pair*)b; 

    return preferences[pb.winner][pb.loser] - preferences[pa.winner][pa.loser];
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    qsort(pairs, pair_count, sizeof(pair), compare); 
    return;
}


// Recursively checks if the given candidate 'a' can beat 'b', and if so, mark 
// dalocked and returns true, else false
static bool beats(int a, int b)
{
    // Base case 
    if (dalocked[b][a]) return false;

    for (int i = 0; i < candidate_count; i++)
    {
        // Recurse on all subgraphs that are beaten by b
        if (i == b || i == a) continue;
        if (dalocked[b][i]) 
        {
            if (!beats(a, i)) return false;
        }
    }

    dalocked[a][b] = true;

    return true;
}

void clear_graph(bool graph[9][9])
{
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            dalocked[i][j] = false;
        }
    } 
    return;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    clear_graph(dalocked);

    for (int i = 0; i < pair_count; i++)
    {
        beats(pairs[i].winner, pairs[i].loser);
    }

    // Translate from dalocked to locked
    for (int i = 0; i < pair_count; i++)
    {
        if (dalocked[pairs[i].winner][pairs[i].loser])
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    return;
}

// Prints a graph (can use on locked or dalock) in dot format
static void print_graph(FILE* f, bool graph[9][9])
{
    fprintf(f, "digraph {\n");

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (graph[i][j])
            {
                fprintf(f, "\t%s -> %s;\n", candidates[i], candidates[j]);
            }
        }
    }

    fprintf(f, "}\n");
}

// Print the winner of the election
void print_winner(void)
{
    // Check the column (candidate) that is not beaten by anyone
    for (int i = 0; i < candidate_count; i++)
    {
        bool isbeaten = false;
        for (int j = 0; j < candidate_count; j++)
        {
            if (locked[j][i]) 
            { 
                isbeaten = true;
            }
        }

        if (!isbeaten) printf("%s\n", candidates[i]);
    }
    return;
}

