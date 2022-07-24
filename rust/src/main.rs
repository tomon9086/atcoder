mod create_contest;

use clap::{Parser, Subcommand};
use create_contest::create_contest;

#[derive(Parser)]
#[clap()]
struct AppArg {
    #[clap(subcommand)]
    action: Action,
}

#[derive(Subcommand)]
enum Action {
    Create { name: String },
    Debug {},
}

fn main() {
    let arg: AppArg = AppArg::parse();

    match arg.action {
        Action::Create { name } => {
            create_contest(name);
        }
        Action::Debug {} => {
            println!("running...");
        }
    }
}
