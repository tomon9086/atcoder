use std::{fs, io::Write};

pub fn create_contest(name: String) {
    let _ = fs::write(
        format!("src/{}.rs", name),
        format!(
            "pub fn {}_a() {{
    println!(\"hoge\");
}}
",
            name
        ),
    )
    .and_then(|_| {
        fs::OpenOptions::new()
            .append(true)
            .open(format!("src/main.rs"))
            .and_then(|mut f| {
                f.write(
                    format!(
                        "mod {};
",
                        name
                    )
                    .as_bytes(),
                )
            })
    });
}
