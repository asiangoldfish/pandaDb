#!/usr/bin/python3

# Imports
import click


@click.command()
@click.option(
    '-h', '--host',
    prompt=True,
)
def start_server(host):
    click.echo(f"Starting server at {host}")


@click.group()
def cli():
    pass


cli.add_command(start_server)

cli()
