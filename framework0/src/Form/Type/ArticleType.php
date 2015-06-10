<?php

namespace Framework0\Form\Type;

use Symfony\Component\Form\AbstractType;
use Symfony\Component\Form\FormBuilderInterface;

class ArticleType extends AbstractType
{
    public function buildForm(FormBuilderInterface $builder, array $options)
    {
        $builder
            ->add('title', 'text')
            ->add('content', 'textarea')
            ->add('preview', 'textarea')
            ->add('subject', 'textarea');
    }

    public function getName() { return 'article'; }
}
