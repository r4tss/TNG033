    Set& s = new Set{};
    Node* n1 = head->next;
    Node* n2 = b.head->next;
    Node* n3 = s.head;

    while(n1->next != nullptr && n2->next != nullptr)
    {
        if(n1->value < n2->value)
        {
            n3->next = new Node{n1->value, nullptr};
            n3 = n3->next;
            s.counter++;

            n1 = n1->next;
        }
        else if(n2->value < n1->value)
        {
            n3->next = new Node{n2->value, nullptr};
            n3 = n3->next;
            s.counter++;

            n2 = n2->next;
        }
        else
        {
            n3->next = new Node{n1->value, nullptr};
            n3 = n3->next;
            s.counter++;

            n1 = n1->next;
            n2 = n2->next;
        }
    }
    if(n1->next == nullptr)
    {
        n3->next = new Node{n1->value, nullptr};
        n3 = n3->next;
        s.counter++;
    }
    else if(n2->next == nullptr)
    {
        n3->next = new Node{n2->value, nullptr};
        n3 = n3->next;
        s.counter++;
    }

    while(n1->next != nullptr)
    {
        n3->next = new Node{n1->value, nullptr};
        n3 = n3->next;
        s.counter++;

        n1 = n1->next;
    }
    if(!member(n1->value))
    {
        n3->next = new Node{n1->value, nullptr};
        s.counter++;
    }

    while(n2->next != nullptr)
    {
        n3->next = new Node{n2->value, nullptr};
        n3 = n3->next;
        s.counter++;

        n2 = n2->next;
    }
    if(!member(n2->value))
    {
        n3->next = new Node{n2->value, nullptr};
        s.counter++;
    }

    //Set s;
    //Node* n1 = head->next;
    //Node* n2 = b.head->next;
    //Node* n3 = s.head;

    //while(n1->next != nullptr && n2->next != nullptr)
    //{
    //    if(n1->value < n2->value)
    //    {
    //        n3->next = new Node{n1->value, nullptr};
    //        n3 = n3->next;
    //        s.counter++;

    //        n1 = n1->next;
    //    }
    //    else if(n2->value < n1->value)
    //    {
    //        n3->next = new Node{n2->value, nullptr};
    //        n3 = n3->next;
    //        s.counter++;

    //        n2 = n2->next;
    //    }
    //    else
    //    {
    //        n3->next = new Node{n1->value, nullptr};
    //        n3 = n3->next;
    //        s.counter++;

    //        n1 = n1->next;
    //        n2 = n2->next;
    //    }
    //}
    //if(n1->next == nullptr && n1->value < n2->value)
    //{
    //    n3->next= new Node{n1->value, nullptr};
    //    n3 = n3->next;
    //    s.counter++;
    //}
    //else if(n2->next == nullptr && n2->value < n1->value)
    //{
    //    n3->next= new Node{n2->value, nullptr};
    //    n3 = n3->next;
    //    s.counter++;
    //}

    //while(n1->next != nullptr)
    //{
    //    if(!s.member(n2->value))
    //    {
    //        n3->next = new Node{n2->value, nullptr};
    //        n3 = n3->next;
    //        s.counter++;
    //    }
    //    else
    //    {
    //        n3->next = new Node{n1->value, nullptr};
    //        n3 = n3->next;
    //        s.counter++;

    //        n1 = n1->next;
    //    }
    //}

    //while(n2->next != nullptr)
    //{
    //    if(!s.member(n1->value))
    //    {
    //        n3->next = new Node{n1->value, nullptr};
    //        n3 = n3->next;
    //        s.counter++;
    //    }
    //    else
    //    {
    //        n3->next = new Node{n2->value, nullptr};
    //        n3 = n3->next;
    //        s.counter++;

    //        n2 = n2->next;
    //    }
    //}

    //if(n1->value > n2->value)
    //{
    //    n3->next = new Node{n1->value, nullptr};
    //    s.counter++;
    //}
    //else
    //{
    //    n3->next = new Node{n2->value, nullptr};
    //    s.counter++;
    //}

    //return s;
