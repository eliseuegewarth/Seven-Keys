# SevenKeys

## methods

## Constructor  SevenKeys::SevenKeys(): Game("fone")
### *local* AudioManagerMusic * music2 = new AudioManagerMusic();
### *global* lives = 5;
### *global* sanity = 100;

## Level * SevenKeys::load_level(const string& id)

        return new FrontEnd("logo", "logo", "res/images/fone.png");

        return new FrontEnd("logo", "tecnologias", "res/images/manateam.png");

        return new FrontEnd("tecnologias", "classificacao", "res/images/tecnologias.png");

        return new FrontEnd("classificacao", "title", "res/images/classificacao_indicativa.png");

        return new TitleScreen();

        return new Options();

        Environment *env = Environment::get_instance();
        shared_ptr <Font> font = env->resources_manager->get_font("res/fonts/TakaoExGothic.ttf");

        double w = env->canvas->w();
        double h = env->canvas->h();

        string ant = id;

        Level *lvl = new Level(id, id);

        char novo[256];
        string num_id = id.substr(5,5);
        char num_id2[10];
        
        int novo_id = atoi(num_id2);
        char path[256];

        char music_path[256];
        return new FrontEnd(id, novo, path);

        Environment *env = Environment::get_instance();
        shared_ptr <Font> font = env->resources_manager->get_font("res/fonts/TakaoExGothic.ttf");
        double w = env->canvas->w();
        double h = env->canvas->h();

        string ant = id;

        Level *lvl = new Level(id, id);

        char novo[256];
        lives -= 1;

        return new FrontEnd(id, novo, "res/images/transition.png");

        Environment *env = Environment::get_instance();

        double w = env->canvas->w();
        double h = env->canvas->h();

        Level *lvl = new Level(id, id);
        return new FrontEnd(id, "title", "res/interface/transicao/gameOver.png");

        return new Stage(id, lives, &sanity);

        return new Creditos();

        return new Extras();

    return nullptr;
